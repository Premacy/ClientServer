#pragma once

#include <iostream>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <chrono>

//template<typename T>
class IFunctorType{
public:
	virtual void operator()() = 0;
};

// class ITimer{
// public:
// 	virtual void start() = 0;
// 	virtual void stop () = 0;

// 	virtual void isRunning() const = 0;
// };

class TimerFunction{
public:

	using duration_t = std::chrono::duration<double>;

	TimerFunction(): isRun(false), func(nullptr) {};

	void setTimer(IFunctorType *func_, duration_t duration_);

	void start();
	void startTimerLoop();

	bool isRunning( ) const;
	bool isFinish ( ) const;

private:

	void doStart();

private:
	bool isRun;

	IFunctorType *func;
	duration_t duration;
};