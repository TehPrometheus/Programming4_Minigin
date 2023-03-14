#pragma once
#include "TextObject.h"
namespace dae {
	//todo: this should only inherit from baseComponent. To solve this make sure that you attach
	class FPSCounter final : public TextObject
	{
	public:
		FPSCounter(const std::string& text, std::shared_ptr<Font> font, GameObject* pOwner);
		~FPSCounter() = default;

		void Update() override;
	};

}

