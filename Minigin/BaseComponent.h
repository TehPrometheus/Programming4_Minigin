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
		//todo: this should be private. pass the owner to the constructor of the component
		//todo: add a protected getter for it
		//todo: remove the setter

		dae::GameObject* m_ParentObject{nullptr};
	};
}
