#include "WorkerThreads.h"


double square(double num)
{
	return num * num;
}

int main()
{
	WorkerThread wrokQueue;
	//wrokQueue.enqueue<double, std::function<double(double)>, double>(&square, 5.0);
	wrokQueue.enqueue<double, std::function<double(double)>, double>(&square, 5.0);
	return 0;
}