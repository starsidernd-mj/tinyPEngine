#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <functional>

namespace tinypengine {
	class Timer {
		private:
			int interval = 0;
			bool running = false;
		
		public:
			Timer(int timeInterval);
			virtual ~Timer();
			
			void start();
			void stop();
			void func();
	};
}

#endif
