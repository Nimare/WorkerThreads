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
	~WorkerThread();
	template<typename ReturnType, typename Function, typename... ParamType>
	inline std::future<ReturnType> WorkerThread::enqueue(Function&& fn, ParamType&&... param)
	{
		{
			std::lock_guard<std::mutex> lock(m_workMutex);
			auto func = std::bind(fn, param...);
			m_workQueue.push_back(std::move(func));
		}
		return std::future<ReturnType>();
	}
	void shutdown();
	void joinAll();

private:
	void threadWrokerLoop();
	std::vector<std::thread> m_threadPool;
	std::deque<std::function<void()>> m_workQueue;
	std::mutex m_workMutex;
	std::atomic<bool> m_shutdown;
};