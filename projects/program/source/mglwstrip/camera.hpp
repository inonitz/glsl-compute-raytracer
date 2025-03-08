#pragma once
#include <util/vec2.hpp>





struct Camera 
{
private:
	const util::math::vec3f worldUp = { 0.0f, 1.0f, 0.0f };
	util::math::vec3f pos;
	util::math::vec3f front;
	util::math::vec2f rotation;
	util::math::mat4f view;

public:
	util::math::vec2f velocity; /* velocity[0] = dx/dt. velocity[1] = d0/dt, Rotation Speed (Angular Velocity) */


	void create(
		util::math::vec3f const& initialPosition, 
		util::math::vec3f const& frontDirection = { 0.0f, 0.0f, 1.0f }, 
		util::math::vec2f const& speeds 		  = { 1.0f, 0.2f } /* speeds = { movementSpeed, rotationSpeed } */
	);

	void onUpdate(f32 dt);


	__force_inline util::math::mat4f const& constref() const { return view;  }
	__force_inline util::math::mat4f const* constptr() const { return &view; }
	__force_inline util::math::vec3f const& position() const { return pos;   }
	__force_inline util::math::vec3f       lookingAt() const { return pos + front; }

private:
	__force_inline void recalcView() {
		util::math::lookAt(pos, pos + front, worldUp, view);
		return;
	}
};




struct ProjectionMatrix 
{
private:
	util::math::mat4f data;

	struct underlying_names 
	{
		f32 aspectRatio;
		f32 fieldOfView;
		f32 nearClip;
		f32 farClip;
	};
public:
	union 
	{
		underlying_names  __;
		util::math::vec4f parameters;
	};
	
	
	ProjectionMatrix() : parameters{} { util::math::identity(data); return; }


	void create(util::math::vec4f const& initialParamters)
	{
		parameters = initialParamters; 
		recalculate();
		return;
	}


	__force_inline void recalculate() 
	{ 
		util::math::perspective(
			__.aspectRatio, 
			__.fieldOfView, 
			__.nearClip, 
			__.farClip, 
			data
		); 
		return;
	}
	__force_inline util::math::mat4f const& constref() const { return data;  }
	__force_inline util::math::mat4f const* constptr() const { return &data; }
};