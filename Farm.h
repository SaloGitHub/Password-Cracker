#pragma once

#include "Task.h"
#include <queue>
#include <mutex>

class Farm
{
public:
	void add_task(Task* task);
	void run();
	void DeleteThreads();
	void RunThreads();

private:
	std::mutex mtx;
	std::queue<Task*> taskQ;
	std::vector<std::thread*> threads;
	int cpus = std::thread::hardware_concurrency();
};