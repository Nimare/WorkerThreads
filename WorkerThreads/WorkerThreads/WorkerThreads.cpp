#include "WorkerThreads.h"

WorkerThread::WorkerThread(unsigned int numberOfThreads) : m_threadPool(), m_shutdown(false)
{
	for (unsigned int i = 0; i < numberOfThreads; ++i)
	{
		m_threadPool.emplace_back(std::thread(&WorkerThread::threadWrokerLoop, this));
	}
}

WorkerThread::~WorkerThread()
{
	shutdown();
}

void WorkerThread::shutdown()
{
	m_shutdown = true;
	joinAll();
}

void WorkerThread::joinAll()
{
	for (auto& thr : m_threadPool)
	{
		if (thr.joinable())
			thr.join();
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
		if (m_shutdown)
			break;
	}
}