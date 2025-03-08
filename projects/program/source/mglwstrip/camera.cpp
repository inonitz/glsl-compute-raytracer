#include "camera.hpp"
#include <awc2/C/awc2.h>
#include <algorithm>




void Camera::create(
	util::math::vec3f const& initialPosition, 
	util::math::vec3f const& frontDirection,
	util::math::vec2f const& speeds
) {
	pos 	 = initialPosition;
	front    = frontDirection;
	velocity = speeds;

	rotation = {0.0f, 0.0f};
	util::math::identity(view);
	return;
}


void Camera::onUpdate(f32 dt)
{
	util::math::vec2f delta, rotRad; 
	util::math::vec3f right = util::math::cross(worldUp, front);
	right.normalize();
	if(awc2isKeyPressed(AWC2_KEYCODE_W) || awc2isKeyRepeated(AWC2_KEYCODE_W) ) { pos += front * (dt * velocity.u); }
	if(awc2isKeyPressed(AWC2_KEYCODE_S) || awc2isKeyRepeated(AWC2_KEYCODE_S) ) { pos -= front * (dt * velocity.u); }
	if(awc2isKeyPressed(AWC2_KEYCODE_D) || awc2isKeyRepeated(AWC2_KEYCODE_D) ) { pos -= right * (dt * velocity.u); }
	if(awc2isKeyPressed(AWC2_KEYCODE_A) || awc2isKeyRepeated(AWC2_KEYCODE_A) ) { pos += right * (dt * velocity.u); }


	AWC2CursorPosition __delta = awc2getMousePositionDelta();
	delta = util::math::vec2f(__delta.x, __delta.y) * velocity.v;
	if(delta.x != 0.0f && delta.y != 0.0f) 
	{
		rotation += delta * dt;
		rotation.pitch = std::clamp(rotation.pitch, -89.0f, 89.0f);
		rotRad = { util::math::radians(rotation.yaw  ), util::math::radians(rotation.pitch) };
		front = {
			cosf(rotRad.yaw) * cosf(rotRad.pitch),
			sinf(rotRad.pitch),
			sinf(rotRad.yaw) * cosf(rotRad.pitch)
		};
		front.normalize();
	}

	recalcView();
	return;
}