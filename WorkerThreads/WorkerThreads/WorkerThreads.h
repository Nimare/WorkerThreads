#pragma once

#include <vector>
#include <thread>

class WorkerThread
{
public:
	WorkerThread(): WorkerThread(std::thread::hardware_concurrency()) {};
	WorkerThread(unsigned int numberOfThreads) : m_threadPool()
	{
		for (unsigned int i; i < numberOfThreads; ++i)
		{
			m_threadPool.emplace_back(std::thread(&WorkerThread::threadWrokerLoop, this));
		}
	}
	~WorkerThread() {};
private:
	void threadWrokerLoop()
	{
	}
	std::vector<std::thread> m_threadPool;
};