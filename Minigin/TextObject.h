#pragma once
#include <string>
#include <memory>
#include "BaseComponent.h"
#include "Transform.h"

namespace dae
{
	class Font;
	class Texture2D;
	class TextObject: public BaseComponent
	{
	public:
		TextObject(const std::string& text, std::shared_ptr<Font> font, GameObject* pOwner);
		virtual ~TextObject() override = default ;

		TextObject(const TextObject& other) = delete;
		TextObject(TextObject&& other) = delete;
		TextObject& operator=(const TextObject& other) = delete;
		TextObject& operator=(TextObject&& other) = delete;

		virtual void Update() override;
		void Render() const override;

		void SetText(const std::string& text);
		void SetPosition(float x, float y);
	protected:
		std::string m_Text;

	private:
		bool m_needsUpdate;
		std::shared_ptr<Font> m_Font;
		std::shared_ptr<Texture2D> m_TextTexture;
	};
}
