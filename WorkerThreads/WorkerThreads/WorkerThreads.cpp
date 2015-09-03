#include "WorkerThreads.h"

WorkerThread::WorkerThread(unsigned int numberOfThreads) : m_threadPool()
{
	for (unsigned int i = 0; i < numberOfThreads; ++i)
	{
		m_threadPool.emplace_back(std::thread(&WorkerThread::threadWrokerLoop, this));
	}
}


void WorkerThread::threadWrokerLoop()
{
	while(true)
	{
		std::function<void()> func;
		{
			std::lock_guard<std::mutex> lock(m_workMutex);
			if (!m_workQueue.empty())
			{
				func = std::move(m_workQueue.front());
				m_workQueue.pop_front();
			}
			if (func)
				func();
		}
	}
}