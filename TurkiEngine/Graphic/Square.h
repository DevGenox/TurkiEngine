#pragma once
#include "../GameObjects/GameObject.h"
namespace Turki
{
	class Square : public GameObject
	{
	public:
		Square();
		~Square();
		void create(Shaders& drawShader, VertexArray& vao, mat4 pr_Mat, vec3 position, float Angle, vec3 rotRoute, vec3 scaleSize);
		void draw(vec3 position, float Angle, vec3 rotRoute);

		int dx = 1;
		int dy = 1;
	private:

	};

	
}