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
	template<typename ReturnType, typename Function, typename... ParamType>
	inline std::future<ReturnType> WorkerThread::enqueue(Function&& fn, ParamType&&... param)
	{
#if 0
		{
			std::lock_guard<std::mutex> lock(m_workMutex);
			m_workQueue.push_back(fn);
		}
#endif
		return std::future<ReturnType>();
	}

private:
	void threadWrokerLoop();
	std::vector<std::thread> m_threadPool;
	std::deque<std::function<void()>> m_workQueue;
	std::mutex m_workMutex;
};