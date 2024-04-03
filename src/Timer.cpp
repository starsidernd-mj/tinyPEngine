
#include "Timer.hpp"

namespace tinypengine {
	Timer::Timer(int timeInterval) {
	
	
	}
	
	Timer::~Timer() {}
	
	void Timer::start() {
		running = true;
	}
	
	void Timer::stop() {
		running = false;
	}
	
	
}
