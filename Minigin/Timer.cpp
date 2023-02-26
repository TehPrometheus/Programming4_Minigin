#include "Timer.h"

void Timer::UpdateDt()
{
	auto newCurrentTime{ high_resolution_clock::now() };
	m_Dt = duration<double>(newCurrentTime - currentTime).count();
	currentTime = newCurrentTime;
}
