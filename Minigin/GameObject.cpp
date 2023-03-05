#include "GameObject.h"
#include <functional>
#include "Exceptions.h"
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


void dae::GameObject::SetParent(GameObject* parent, bool keepWorldPosition)
{
	auto transform{ GetTransform() };
	if (parent == nullptr)
		transform->SetLocalPosition(transform->GetWorldPosition().x, transform->GetWorldPosition().y, transform->GetWorldPosition().z);
	else
	{
		if (keepWorldPosition)
		{
			auto pos{ transform->GetLocalPosition() - parent->GetTransform()->GetWorldPosition() };
			transform->SetLocalPosition(pos.x, pos.y, pos.z);
		}
		transform->SetPositionFlag(true);
	}

	if(m_Parent)
		m_Parent->RemoveChild(this);
	m_Parent = parent;
	if (m_Parent)
		m_Parent->AddChild(this);
}

void dae::GameObject::SetWorldPosition(float x, float y)
{
	GetTransform()->SetWorldPosition(x, y, 0.0f);
}

dae::Transform* dae::GameObject::GetTransform() const
{
	return GetComponent<Transform>();
}

void dae::GameObject::RemoveChild(GameObject* child)
{
	const size_t numElementsErased{ m_Children.erase(child) };
	if(numElementsErased == 0)
		throw ChildNotFoundException();
}

void dae::GameObject::AddChild(GameObject* child)
{
	// No need to check if child is already in m_Children since it's a set.
	const auto pair{ m_Children.insert(child) };
	if (pair.second == false)
		throw GameObjectIsAlreadyChildException();
}
