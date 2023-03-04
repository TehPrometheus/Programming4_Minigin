#include "Transform.h"

dae::Transform::Transform(GameObject* pOwner, const float x, const float y, const float z)
	:BaseComponent(pOwner)
{
	SetPosition(x, y, z);
}

void dae::Transform::SetPosition(const float x, const float y, const float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

void dae::Transform::Update()
{
}

void dae::Transform::Render() const
{
}
