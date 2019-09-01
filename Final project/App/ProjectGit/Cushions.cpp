/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by Kirsty McEwan, Lauren McNally, Matthew McMahon Wood as a group assignment for the Game Physics module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "Cushions.h"

void Cushions::update(float dt)
{
}

void Cushions::Draw(int width, int height)
{
	vec2 position = Parameters->transform.getPosition();

	glLoadIdentity();
	float aspectRatio = (width / (float)height);
	glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
		(position.y - (0.5f * height)) / (0.5f * height), 0.0f);

	glBegin(GL_QUADS);
	glColor3f(color.r, color.g, color.b);
	glVertex2f(2 * radius.x * aspectRatio / width, 2 * radius.y / height);
	glVertex2f(-2 * radius.x * aspectRatio / width, 2 * radius.y / height);
	glVertex2f(-2 * radius.x * aspectRatio / width, -2 * radius.y / height);
	glVertex2f(2 * radius.x * aspectRatio / width, -2 * radius.y / height);
	glEnd();
}

