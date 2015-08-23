#pragma once

#include <vector>
#include <thread>
#include <functional>
#include <future>
#include <deque>

class WorkerThread
{
public:
	WorkerThread(): WorkerThread(std::thread::hardware_concurrency()) {};
	WorkerThread(unsigned int numberOfThreads);
	template <class jobType>
	std::future<jobType> enqueue(std::function<jobType>);

private:
	void threadWrokerLoop()
	{
	}
	std::vector<std::thread> m_threadPool;
	std::deque<std::function<void()>> m_workQueue;
	std::mutex m_workMutex;
};