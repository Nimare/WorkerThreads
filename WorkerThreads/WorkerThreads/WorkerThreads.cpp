#include "WorkerThreads.h"

WorkerThread::WorkerThread(unsigned int numberOfThreads) : m_threadPool()
{
	for (unsigned int i = 0; i < numberOfThreads; ++i)
	{
		m_threadPool.emplace_back(std::thread(&WorkerThread::threadWrokerLoop, this));
	}
}

template<class jobType>
inline std::future<jobType> WorkerThread::enqueue(std::function<jobType>)
{
	return std::future<jobType>();
}