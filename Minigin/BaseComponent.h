#pragma once
#include "Transform.h"

namespace dae
{
	class BaseComponent
	{
	public:
		BaseComponent(Transform transform);
		virtual ~BaseComponent() = default;

		virtual void Update() = 0;
		virtual void Render() const = 0;


	protected:
		Transform m_Transform;
	};
}
