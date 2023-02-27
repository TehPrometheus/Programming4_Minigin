#include "Timer.h"
#include <SDL.h>

Timer::Timer()
{
	const uint64_t countPerSecond = SDL_GetPerformanceFrequency();
	m_SecondsPerCount = 1.f / static_cast<float>(countPerSecond);
	m_PreviousTime = SDL_GetPerformanceCounter(); // ensures that the first m_Dt is small, otherwise long load time.
}

void Timer::Update()
{
	UpdateDt();
	UpdateFPS();
}

void Timer::UpdateDt()
{
	m_CurrentTime = SDL_GetPerformanceCounter();
	m_Dt = static_cast<float>(m_CurrentTime - m_PreviousTime) * m_SecondsPerCount;
	m_PreviousTime = m_CurrentTime;

	if (m_Dt < 0.f)
		m_Dt = 0.f;

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
