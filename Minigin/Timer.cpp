#include "Timer.h"

void Timer::UpdateDt(steady_clock::time_point newCurrentTime)
{
	m_Dt = duration<double>(newCurrentTime - currentTime).count();
	currentTime = newCurrentTime;
}
