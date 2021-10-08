#pragma once
#include "glm/mat4x4.hpp"


class Camera
{
public:
	Camera() {}
	Camera(float fieldOfView, float nearClip, float FarClip)
		: m_fieldofView{ fieldOfView }, m_nearClip{ nearClip }, m_farClip{ FarClip } {}
	~Camera() {}

	//glm::mat4 getTransform() { return m_transform; }
	//void setTransform(glm::mat4 Transfrom) { m_transform = Transfrom; }
	glm::mat4 getViewMatrix();
	glm::vec3 getPosition() { return m_position; }
	void setPosition(glm::vec3 Position) { m_position = Position; }
	float getYaw() { return m_theta; }
	void setYaw(float Theta) { m_theta = Theta; }
	float getPitch() { return m_phi; }
	void setPitch(float Phi) { m_phi = Phi; }

	float getFieldOfView() { return m_fieldofView; }
	void setFieldOfView(float FieldOfView) { m_fieldofView = FieldOfView; }
	float getNearClip() { return m_nearClip; }
	void setNearClip(float NearClip) { m_nearClip = NearClip; }
	float getFarClip() { return m_farClip; }
	void setFarClip(float FarClip) { m_farClip = FarClip; }

private:
	//glm::mat4 m_transform = glm::mat4(1.0f);
	glm::vec3 m_position{ 0.0f, 0.0f, 0.0f };
	float m_theta{ 0.0f };
	float m_phi{0.0f};

	float m_fieldofView{ 45.0f };
	float m_nearClip{ 0.001f };
	float m_farClip{ 1000.0f };


};

