#include "Timer.h"
#include "RotatorComponent.h"
#include "GameObject.h"

dae::RotatorComponent::RotatorComponent(GameObject* pOwner, glm::vec2 center, float radius, float angularVelocity)
	:BaseComponent(pOwner)
	,m_Center(center)
	,m_Radius(radius)
	,m_AngularVelocity(angularVelocity)
{
}

void dae::RotatorComponent::Update()
{
	m_CurrentAngle += m_AngularVelocity * static_cast<float>(TIMER.GetDt());

	if(GetOwner()->GetParent() == nullptr)
	{
		GetOwner()->GetTransform()->SetWorldPosition
		(	
			m_Center.x + m_Radius * glm::sin(m_CurrentAngle),
			m_Center.y + m_Radius * glm::cos(m_CurrentAngle)
		);
	}
	else
	{
		GetOwner()->GetTransform()->SetWorldPosition
		(
			// This is not correct, I'm unsure how to do it differently
			GetOwner()->GetParent()->GetTransform()->GetWorldPosition().x + m_Radius * glm::sin(m_CurrentAngle),
			GetOwner()->GetParent()->GetTransform()->GetWorldPosition().y + m_Radius * glm::cos(m_CurrentAngle)
		);
	}
}

void dae::RotatorComponent::Render() const
{
}