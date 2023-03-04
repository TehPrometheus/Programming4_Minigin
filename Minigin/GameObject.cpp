#include "GameObject.h"
#include <functional>

#include "Texture2D.h"

dae::GameObject::GameObject(const float x, const float y, const float z)
{
	AddComponent<dae::Transform>(new Transform(this, x, y, z));
}

dae::GameObject::~GameObject()
{
	for (auto c: m_Components)
	{
		delete c.second;
	}
}

void dae::GameObject::Update()
{
	for (auto c: m_Components)
	{
		c.second->Update();
	}
}

void dae::GameObject::Render() const
{
	for (auto c: m_Components)
	{
		c.second->Render();
	}
}


void dae::GameObject::SetPosition(float x, float y)
{
	GetTransform()->SetPosition(x, y, 0.0f);
}

dae::Transform* dae::GameObject::GetTransform() const
{
	return GetComponent<Transform>();
}
