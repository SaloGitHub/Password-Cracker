#include "Farm.h"

#include <iostream>

void Farm::add_task(Task* task) {
	std::unique_lock<std::mutex> lck(mtx);
	taskQ.push(task);
}

void Farm::run() {

	RunThreads();
	DeleteThreads();
}

void Farm::RunThreads() {

	for (int i = 0; i < cpus; i++) {
		threads.push_back(new std::thread([&] {
			while (true) {
				Task* t;

				{
					std::unique_lock<std::mutex> lck(mtx);
					if (taskQ.empty()) {
						return;
					}
					t = taskQ.front();
					taskQ.pop();
				}

				t->run();
			}
			}));
	}

}

void Farm::DeleteThreads() {
	for (int i = 0; i < threads.size(); i++) {
		threads.at(i)->join();
		delete threads.at(i);
	}
}