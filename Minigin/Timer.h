#pragma once
#define TIMER (Timer::GetInstance())
#include "Singleton.h"
#include "Minigin.h"
#include <chrono>
#include <iostream>

using namespace std::chrono;

class Timer final: public dae::Singleton<Timer>
{
public:
	Timer();

	[[nodiscard]] double GetDt() const { return m_Dt; }
	[[nodiscard]] double GetFixedDt() const { return m_FixedDt; }
	[[nodiscard]] double GetFrameFraction() const { return m_FrameFraction; }
	[[nodiscard]] double GetFPS() const { return m_FPS; }

	void Update();

	friend void dae::Minigin::Run(const std::function<void()>& load); // only this function can/needs to set m_Dt value
private:
	float m_SecondsPerCount{};
	double m_AccuSec{};
	double m_FPS{};
	double m_Dt{};
	double m_FrameFraction{}; // how far we are in the next frame expressed in units of fixedDt
	const double m_FixedDt{0.016}; // in seconds

	uint64_t m_CurrentTime{};
	uint64_t m_PreviousTime{};

	void UpdateDt();
	void UpdateFPS();
};