#include "WorkerThreads.h"

WorkerThread::WorkerThread(unsigned int numberOfThreads) : m_threadPool()
{
	for (unsigned int i = 0; i < numberOfThreads; ++i)
	{
		m_threadPool.emplace_back(std::thread(&WorkerThread::threadWrokerLoop, this));
	}
}

template<typename ReturnType,typename... ParamType>
inline std::future<ReturnType> WorkerThread::enqueue(std::function<ReturnType(ParamType)> job)
{
	std::unique_lock<m_workMutex> lock;
	m_orkQueue.push_back(job);
	return std::future<jobType>();
}