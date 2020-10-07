#include "Barrier.h"

#include <iostream>
#include <thread>
#include <vector>

#define SIZE 10000

Barrier barrier;
std::vector<std::unique_ptr<std::thread>> threads;

void foo(int id) {
	printf("Thread %d entered foo \n", id);
	barrier.wait_slave();
	printf("Thread %d passed barrier\n", id);
}

void bar() {
	for(int i = 0;i<SIZE;i++){
		barrier.wait_donor();
	}
}

int main() {
	threads.resize(SIZE);

	for (int i = 0; i < SIZE; i++)	{
		flag.insert(std::make_pair(i, false));
		threads[i].reset(new std::thread(foo, i));
	}

	bar();

	for (int i = 0; i < SIZE; i++)	{
		threads[i]->join();
	}

	return 0;
}
