#include "Timer.h"

Timer::Timer() {
	this->start = std::chrono::high_resolution_clock::now();
}

float Timer::getDuration() {
	this->end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;
	return duration.count();
}