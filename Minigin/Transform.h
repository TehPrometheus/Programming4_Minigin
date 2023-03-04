#pragma once
#include <glm/glm.hpp>
#include "BaseComponent.h"

namespace dae
{
	class Transform : public BaseComponent
	{
	public:
		Transform(GameObject* pOwner, const float x = 0, const float y = 0, const float z = 0);
		~Transform() override = default;

		Transform(const Transform&) = delete;
		Transform(Transform&&) = delete;
		Transform& operator= (const Transform&) = delete;
		Transform& operator= (const Transform&&) = delete;

		[[nodiscard]] const glm::vec3& GetPosition() const { return m_position; }
		void SetPosition(float x, float y, float z);
		void Update() override;
		void Render() const override;

	private:
		glm::vec3 m_position{};
	};
}
