#include "Transform.h"

#include "GameObject.h"

dae::Transform::Transform(GameObject* pOwner, float x, float y, float z)
	:BaseComponent(pOwner)
{
	SetWorldPosition(x, y, z);
}

void dae::Transform::SetWorldPosition(float x, float y, float z)
{
	m_WorldPosition.x = x;
	m_WorldPosition.y = y;
	m_WorldPosition.z = z;
}

void dae::Transform::SetLocalPosition(float x, float y, float z)
{
	m_LocalPosition.x = x;
	m_LocalPosition.y = y;
	m_LocalPosition.z = z;

	m_PositionIsDirty = true;
}

void dae::Transform::UpdateWorldPosition()
{
	if(m_PositionIsDirty)
	{
		const GameObject* parent{ GetOwner()->GetParent() };

		if (parent == nullptr)
			m_WorldPosition = m_LocalPosition;
		else
			m_WorldPosition = parent->GetTransform()->GetWorldPosition() + m_LocalPosition;
	}
	m_PositionIsDirty = false;
}

void dae::Transform::Update()
{
}

void dae::Transform::Render() const
{
}

const glm::vec3& dae::Transform::GetWorldPosition()
{
	if (m_PositionIsDirty)
		UpdateWorldPosition();
	return m_WorldPosition;
}

