#pragma once
#include <string>
#include <glm/vec2.hpp>
#include "BaseComponent.h"

struct SDL_Texture;
namespace dae
{
	class Texture2D final: public BaseComponent
	{
	public:
		explicit Texture2D(SDL_Texture* texture);
		explicit Texture2D(const std::string& filename, GameObject* pOwner);
		~Texture2D() override;

		Texture2D(const Texture2D &) = delete;
		Texture2D(Texture2D &&) = delete;
		Texture2D & operator= (const Texture2D &) = delete;
		Texture2D & operator= (const Texture2D &&) = delete;

		void Render() const override;
		void Update() override;
		void SetTexture(const std::string& filename);

		[[nodiscard]] glm::ivec2 GetSize() const;
		[[nodiscard]] SDL_Texture* GetSDLTexture() const;

		void SetSize(int width, int height);
	private:
		SDL_Rect m_DestRect{};
		SDL_Texture* m_Texture{nullptr};
	};
}
