#include <SDL.h>
#include "Texture2D.h"

#include "GameObject.h"
#include "ResourceManager.h"
dae::Texture2D::Texture2D(SDL_Texture* texture)
{
	m_Texture = texture;
}

dae::Texture2D::Texture2D(const std::string& filename, GameObject* pOwner)
	:BaseComponent(pOwner)
{
	SetTexture(filename);
	SDL_QueryTexture(GetSDLTexture(), nullptr, nullptr, &m_DestRect.w, &m_DestRect.h);
}

dae::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_Texture);
}

void dae::Texture2D::Update()
{

}

void dae::Texture2D::Render() const
{
	const auto& pos{ GetOwner()->GetTransform()->GetWorldPosition() };
	Renderer::GetInstance().RenderTexture(*this, pos.x, pos.y, static_cast<float>(m_DestRect.w), static_cast<float>(m_DestRect.h));
}


void dae::Texture2D::SetTexture(const std::string& filename)
{
	m_Texture = ResourceManager::GetInstance().LoadSDLTexture(filename);
}

glm::ivec2 dae::Texture2D::GetSize() const
{
	SDL_Rect dst;
	SDL_QueryTexture(GetSDLTexture(), nullptr, nullptr, &dst.w, &dst.h);
	return { dst.w,dst.h };
}

SDL_Texture* dae::Texture2D::GetSDLTexture() const
{
	return m_Texture;
}

void dae::Texture2D::SetSize(int width, int height)
{
	m_DestRect.w = width;
	m_DestRect.h = height;
}

