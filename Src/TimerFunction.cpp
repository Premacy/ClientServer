#include "TimerFunction.h"

#include <iostream>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <chrono>

void TimerFunction::setTimer(IFunctorType *func_, duration_t duration_){
	func = func_;
	duration = duration_;
}

void TimerFunction::start(){
	doStart();
}

void TimerFunction::startTimerLoop(){
	while(1){
		if( isFinish() ) doStart();
	}
}

bool TimerFunction::isRunning() const{
	return isRun;
}

bool TimerFunction::isFinish() const{
	return !isRun;
}

void TimerFunction::doStart(){
	auto startTime = std::chrono::steady_clock::now();
	auto endTime   = std::chrono::steady_clock::now();
	duration_t dt = endTime - startTime;

	isRun = true;
	
	while( dt < duration){
		auto endTime   = std::chrono::steady_clock::now();
		dt = endTime - startTime;
	}

	(*func)();

	isRun = false;
}
