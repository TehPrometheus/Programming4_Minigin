#include "GameObject.h"
#include <functional>

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
	m_Transform.SetPosition(x, y, 0.0f);
}
