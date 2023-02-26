#pragma once
#include <atomic>
#include <unordered_map>

template <typename  ComponentType>
class ComponentMap
{
public:
	typedef typename std::unordered_map<int, ComponentType>::iterator iterator;
	typedef typename std::unordered_map<int, ComponentType>::const_iterator const_iterator;
	typedef typename std::unordered_map<int, ComponentType>::value_type value_type;

	const_iterator begin() const { return m_Map.begin(); };
	const_iterator end() const { return m_Map.end(); };
	iterator begin() { return m_Map.begin(); };
	iterator end() { return m_Map.end(); };

	template <typename Key>
	iterator find() { return m_Map.find(GetTypeId<Key>()); }

	template <typename Key>
	const_iterator find() const { return m_Map.find(GetTypeId<Key>()); }

	template <typename Key>
	void add(ComponentType&& value) { m_Map[GetTypeId<Key>()] = std::forward<ComponentType>(value); }

	template <typename Key>
	bool erase();

private:
	template <typename Key>
	static int GetTypeId();

	static std::atomic_int LastTypeId;
	std::unordered_map<int, ComponentType> m_Map;
};

