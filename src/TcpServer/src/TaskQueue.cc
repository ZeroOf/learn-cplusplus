#include "TaskQueue.h"
#include <iostream>

using namespace wiz;

TaskQueue::TaskQueue(int queSize)
: _queSize(queSize)
, _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
, _flag(true)
{}

bool TaskQueue::full()const
{
	return _queSize == _que.size();
}

bool TaskQueue::empty() const
{
	return 0 == _que.size();
}

void TaskQueue::push(Type && elem)
{
	MutexLockGuard autoLock(_mutex);
	while(full())
	{
		_notFull.wait();
	}
	_que.push(std::move(elem));
	_notEmpty.notify();
}

TaskQueue::Type TaskQueue::pop()
{
	MutexLockGuard autoLock(_mutex);
	while(_flag && empty())
	{
		_notEmpty.wait();
	}

	if(_flag){
		Type tmp = _que.front();
		_que.pop();
		_notFull.notify();
		return tmp;
	}else
		return nullptr;
}

void TaskQueue::wakeup()
{
	_flag = false;
	_notEmpty.notifyAll();
}
