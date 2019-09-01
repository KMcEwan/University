/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by Kirsty McEwan, Lauren McNally, Matthew McMahon Wood as a group assignment for the Game Physics module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
//#include <iostream>
//#include "Table.h"
//#include "Cue.h"
//#include "Transform.h"
//
//using namespace std;
//
//#define KEY_UP 72
//#define KEY_DOWN 80
//#define KEY_LEFT 75
//#define KEY_RIGHT 77
//
//void Cue::update(float dt)
//{
//	//glutKeyboardFunc(rotatecue); 
//}
//
//void Cue::move(vec2 traslation)
//{
//	transform.Translate(traslation);
//}
//
///*void Cue::draw(int width, int height)
//{
//	vec2 position = transform.getPosition();
//
//	glLoadIdentity();
//	float aspectRatio = (width / (float)height);
//	glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
//		(position.y - (0.5f * height)) / (0.5f * height), 0.0f);
//
//	glBegin(GL_QUADS);
//	glColor3f(color.r, color.g, color.b);
//	glVertex2f(2 * radius.x * aspectRatio / width, 2 * radius.y / height);
//	glVertex2f(-2 * radius.x * aspectRatio / width, 2 * radius.y / height);
//	glVertex2f(-2 * radius.x * aspectRatio / width, -2 * radius.y / height);
//	glVertex2f(2 * radius.x * aspectRatio / width, -2 * radius.y / height);
//	glEnd();
//}*/
//
//void Cue::setColor(float r, float g, float b)
//{
//	color = vec3(r, g, b);
//}
//
//vec2 Cue::getPosition()
//{
//	return transform.getPosition();
//}
//
//void Cue::rotatecue(unsigned char key, int x, int y1)
//{
//	if (key == GLUT_KEY_RIGHT)
//	{
//		vec2 position = transform.getPosition();
//		glRotatef(position.x, 1.0f, 0.0f, 0.0f);
//
//		// ----- Rotation of Cue ----
//		angle += 0.01f;
//		direction = direction * transform.Rotate(angle);
//
//	}
//		switch (key)
//		{
//		case 27:
//		case 'q':
//			exit(0);
//			break;
//		}
//		glutPostRedisplay();
//}
//
//void Cue::moveCue(unsigned char key, int x, int y1)
//{
//	vec2 position = transform.getPosition();
//
//	switch (key)
//	{
//	case 'w':
//		position.y += 1;
//		break;
//	case 's':
//		position.y -= 1;
//		break;
//	case 'a':
//		position.x -= 1;
//		break;
//	case 'd':
//		position.x += 1;
//		break;
//	}
//	glutPostRedisplay();
//
//}
//
///*void Cue::key(unsigned char key, int x, int y)
//{
//	if (key == GLUT_KEY_RIGHT)
//	{
//		vec2 position = transform.getPosition();
//		glRotatef(position.x, 1.0f, 0.0f, 0.0f);
//	}
//} */
//
///*void Cue::keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 'w':
//		vec2 position = transform.getPosition();
//		glRotatef(position.x, 1.0f, 0.0f, 0.0f);
//		glutPostRedisplay();
//	}
//}*/
//
///*void Cue::onMouseButton(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//	{
//
//		int numb = 0;
//		for (int i = 0; i < 1; i++)
//		{
//			numb = 1;
//			cout << numb << endl;
//			if (numb == 1)
//			{
//				vec2 position = transform.getPosition();
//				glRotatef(position.x, 1.0f, 0.0f, 0.0f);
//				glutPostRedisplay();
//			}
//		}
//
//	}
//}
//
//void Cue::Exit1(unsigned char key, int x, int y1)
//{
//
//	switch (key)
//	{
//	case 27:
//	case 'q':
//		exit(0);
//		break;
//	}
//	glutPostRedisplay();
//} */
//
//
//
// /// ------ OOB Code ----- 
//vec2 Cue::getDirection()
//{
//return direction;
//}
//
//vec2 Cue::getOrtDirection()
//{
//return normalize(vec2(-direction.y, direction.x));
//}
//
//vec2 Cue::getRadius()
//{
//	return radius;
//}
//
//void Cue::draw(int width, int height)
//{
//vec2 position = transform.getPosition();
//
//glLoadIdentity();				// Reset model-view matrix
//float aspectRatio = (width / (float)height);
//vec2 mainDir = (getDirection() * radius.x * aspectRatio) / (float) width;
//vec2 orthDir = (getOrtDirection() * radius.y) / (float) height;
//glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
//(position.y - (0.5f * height)) / (0.5f * height), 0.0f);  // Translate to (xPos, yPos)
//
//glBegin(GL_QUADS);
//glColor3f(color.r, color.g, color.b);
//vec2 vertex = 2.0f * (mainDir + orthDir);
//glVertex2f(vertex.x, vertex.y);
//vertex = 2.0f * (-mainDir + orthDir);
//glVertex2f(vertex.x, vertex.y);
//vertex = 2.0f * (-mainDir - orthDir);
//glVertex2f(vertex.x, vertex.y);
//vertex = 2.0f * (mainDir - orthDir);
//glVertex2f(vertex.x, vertex.y);
//glEnd();
//}
//
//
