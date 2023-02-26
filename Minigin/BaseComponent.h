#pragma once
#include "Renderer.h"

namespace dae
{
	class GameObject;

	class BaseComponent
	{
	public:
		BaseComponent();
		virtual ~BaseComponent() = default;

		virtual void Update() = 0;
		virtual void Render() const = 0;
		void SetParentObject(dae::GameObject* parentObj);

	protected:
		dae::GameObject* m_ParentObject{nullptr};
	};
}
