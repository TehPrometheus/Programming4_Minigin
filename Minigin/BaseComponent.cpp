#include "BaseComponent.h"

dae::BaseComponent::BaseComponent()
{
}

void dae::BaseComponent::SetParentObject(GameObject* parentObj)
{
	m_ParentObject = parentObj;
}
