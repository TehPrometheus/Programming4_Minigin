#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "FPSCounter.h"
#include "Scene.h"
#include "Texture2D.h"
#include "Timer.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	
	auto go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::Texture2D>(new dae::Texture2D("background.tga",go.get()));
	scene.Add(go);

	go = std::make_shared<dae::GameObject>(216.f, 180.f);
	go->AddComponent<dae::Texture2D>(new dae::Texture2D("logo.tga", go.get()));
	scene.Add(go);

	auto font1 = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	go = std::make_shared<dae::GameObject>(80.f, 20.f);
	go->AddComponent<dae::TextObject>(new dae::TextObject("Programming 4 Assignment", font1, go.get()));
	scene.Add(go);

	auto font2 = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 15);
	go = std::make_shared<dae::GameObject>(5.f, 5.f);
	const std::string text{ std::to_string(TIMER.GetFPS()) + " FPS" };
	go->AddComponent<dae::FPSCounter>(new dae::FPSCounter(text, font2, go.get()));
	scene.Add(go);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}