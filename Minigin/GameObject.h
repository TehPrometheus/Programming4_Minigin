#pragma once
#include "Transform.h"
#include "BaseComponent.h"
#include "ComponentMap.h"
#include "Exceptions.h"

namespace dae
{
	class Texture2D;
	class BaseComponent;
	class GameObject 
	{
	public:
		GameObject() = default;
		virtual ~GameObject();

		virtual void Update();
		virtual void Render() const;

		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void SetPosition(float x, float y);
		[[nodiscard]] Transform GetTransform() const { return m_Transform; }

		template <typename ComponentType>
		void AddComponent(BaseComponent* c);

		template <typename ComponentType>
		[[nodiscard]] ComponentType* GetComponent() const;

		template <typename ComponentType>
		bool RemoveComponent();

	private:
		Transform m_Transform{};
		ComponentMap<BaseComponent*> m_Components;
	};

	template <typename ComponentType>
	void GameObject::AddComponent(BaseComponent* c)
	{
		c->SetParentObject(this);
		m_Components.add<ComponentType, BaseComponent*>(c);
	}

	template <typename ComponentType>
	ComponentType* dae::GameObject::GetComponent() const
	{
		auto it{ m_Components.find<ComponentType>() };

		if (it == m_Components.end())
		{
			throw ComponentNotFoundException();
		}

		return it->second;
	}

	// Returns true if removal took place
	template <typename ComponentType>
	bool dae::GameObject::RemoveComponent()
	{
		return m_Components.erase<ComponentType>();
	}

}
