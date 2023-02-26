#include <SDL.h>
#include "Texture2D.h"

#include "GameObject.h"
#include "ResourceManager.h"
dae::Texture2D::Texture2D(SDL_Texture* texture)
	: BaseComponent()
{
	m_texture = texture;
}

dae::Texture2D::Texture2D(const std::string& filename)
	:BaseComponent()
{
	SetTexture(filename);
}

dae::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_texture);
}

void dae::Texture2D::Render() const
{
	const auto& pos{ m_ParentObject->GetTransform().GetPosition() };
	Renderer::GetInstance().RenderSDLTexture(m_texture, pos.x, pos.y);
}

void dae::Texture2D::Update()
{
}

void dae::Texture2D::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadSDLTexture(filename);
}

glm::ivec2 dae::Texture2D::GetSize() const
{
	SDL_Rect dst;
	SDL_QueryTexture(GetSDLTexture(), nullptr, nullptr, &dst.w, &dst.h);
	return { dst.w,dst.h };
}

SDL_Texture* dae::Texture2D::GetSDLTexture() const
{
	return m_texture;
}

