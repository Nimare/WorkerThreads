#include "WorkerThreads.h"


double square(double num)
{
	return num * num;
}

int main()
{
	WorkerThread workQueue;
	//wrokQueue.enqueue<double, std::function<double(double)>, double>(&square, 5.0);
	workQueue.enqueue<double, std::function<double(double)>, double>(&square, 5.0);
	workQueue.shutdown();
	return 0;
}