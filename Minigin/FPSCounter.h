#pragma once
#include "TextObject.h"
namespace dae {

	class FPSCounter final : public TextObject
	{
	public:
		FPSCounter(const std::string& text, std::shared_ptr<Font> font);
		~FPSCounter() = default;

		void Update() override;
	};

}

