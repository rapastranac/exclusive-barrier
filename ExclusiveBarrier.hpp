#ifndef EXCLUSIVEBARRIER_HPP
#define EXCLUSIVEBARRIER_HPP

#include "boost/fiber/barrier.hpp"

#include <atomic>
#include <condition_variable>
#include <thread>

// Copyright 2020
// Author: rapastranac

class ExclusiveBarrier
{
public:
	ExclusiveBarrier() {
		bar.reset(new boost::fibers::barrier(2));
	}

	void wait_donor() {
		std::unique_lock<std::mutex> lck(mtx);
		bar->wait();
	}

	void wait_master() {
		bar->wait();
	}

private:
	std::mutex mtx;
	std::unique_ptr< boost::fibers::barrier> bar;
};


#endif
