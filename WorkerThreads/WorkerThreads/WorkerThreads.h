#pragma once

#include <vector>
#include <thread>
#include <functional>
#include <future>

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
};