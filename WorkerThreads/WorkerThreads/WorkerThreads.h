#pragma once

template <class Item>
class WorkerThread
{
public:
	WorkerThread(Item & it): workItem(it) {};
	~WorkerThread() {};
private:
	Item & workItem;
};