#include "Timer.h"

void Timer::UpdateDt()
{
	auto newCurrentTime{ high_resolution_clock::now() };
	m_Dt = duration<double>(newCurrentTime - currentTime).count();
	currentTime = newCurrentTime;
}

void Timer::UpdateFPS()
{
	static int frameCount{};
	++frameCount;
	m_AccuSec += m_Dt;

	if(m_AccuSec > 1.0)
	{
		m_FPS = frameCount / m_AccuSec;
		frameCount = 0;
		m_AccuSec = 0.0;
	}
}
