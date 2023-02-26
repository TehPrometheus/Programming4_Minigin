#include "FPSCounter.h"
#include "Timer.h"
#include <iostream>

dae::FPSCounter::FPSCounter(const std::string& text, std::shared_ptr<Font> font)
	:TextObject(text,font)
{
}

void dae::FPSCounter::Update()
{
	std::string s{ std::to_string(static_cast<int>(TIMER.GetFPS())) };
	s += " FPS";
	SetText(s);
	TextObject::Update();
}
