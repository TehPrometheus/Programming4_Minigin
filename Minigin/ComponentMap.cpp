#include "ComponentMap.h"

template<typename ValueType>
std::atomic_int ComponentMap<ValueType>::LastTypeId(0);

template<typename ComponentType>
template<typename Key>
bool ComponentMap<ComponentType>::erase()
{
	auto it{ m_Map.find(GetTypeId<Key>()) };

	if(it != m_Map.end())
	{
		m_Map.erase(it);
		return true;
	}

	return false;
}

template<typename ValueType>
template<typename Key>
int ComponentMap<ValueType>::GetTypeId()
{
	static const int id = LastTypeId++;
	return id;
}
