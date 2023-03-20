#include "Scene.h"
#include "GameObject.h"

using namespace dae;

unsigned int Scene::m_idCounter = 0;

Scene::Scene(const std::string& name) : m_name(name) {}

Scene::~Scene()
{
	for(auto& object : m_objects)
	{
		delete object;
	}
}

void Scene::Add( GameObject* object)
{
	m_objects.emplace_back(std::move(object));
}

void Scene::DeleteGameObject(GameObject* object)
{
	//todo: Don't pass in a unique ptr, that won't work. Just pass in a raw pointer and then
	// search in your vector of unique ptr for a match. If a match is found, erase that object from the list and its
	// children
	if (object->GetParent())
		object->SetParent(nullptr);

	for(auto& child : object->GetChildren())
	{
		DeleteGameObject(child);
	}

	delete object;
	m_objects.erase(std::remove(m_objects.begin(), m_objects.end(), object), m_objects.end());
}

void Scene::RemoveAll()
{
	m_objects.clear();
}

void Scene::Update()
{
	for(auto& object : m_objects)
	{
		object->Update();
	}
}

void Scene::Render() const
{
	for (const auto& object : m_objects)
	{
		object->Render();
	}
}

// todo: need to make a DeleteGameObject method, this is what we were referring to with 'RemoveChild'.
// You need to remove this also from the scene if you want full deletion.
// or implement removal from parent objects in scene delete of object. Should remove from scene
// Think about how Unity does this: 1) it destroys it completely. 2) it destroys the children.
// Right now, this memory isn't released
