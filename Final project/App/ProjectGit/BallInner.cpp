/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by Kirsty McEwan, Lauren McNally, Matthew McMahon Wood as a group assignment for the Game Physics module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include <iostream>
#include "BallInner.h"

void BallInner::Draw(int width, int height)
{
	vec2 position = Parameters->transform.getPosition();
	glLoadIdentity();
	float aspectRatio = (width / (float)height);
	glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
		(position.y - (0.5f * height)) / (0.5f * height), 0.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(Color.r, Color.g, Color.b);
	glVertex2f(0.0f, 0.0f);
	int numSegments = 100;
	float angle;
	for (int i = 0; i <= numSegments; i++) {
		angle = i * 2.0f * pi<float>() / numSegments;
		glVertex2f(cos(angle) * (2.0f * Radius / width)* aspectRatio,
			sin(angle) * (2.0f * Radius / height));
	}
	glEnd();
}


void BallInner::update(float dt)
{
	collider->update(Parameters->transform);
}


