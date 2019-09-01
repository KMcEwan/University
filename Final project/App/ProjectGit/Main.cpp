/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by Kirsty McEwan, Lauren McNally, Matthew McMahon Wood as a group assignment for the Game Physics module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include <GL/glut.h>
#include <glm\glm.hpp>
#include "Game.h"
#include "Timer.h"
#include "Table.h"
int refreshMilliseconds = 16;
LowResTimer timer;
double oldTime = 0;

Game *game;																			//Pointer to reference functions in Game

void initGL() 
{
	glClearColor(0.2, 0.2, 0.2, 1.0); 
}

void display() {
	game->Render();
}

void reshape(GLsizei SWidth, GLsizei SHeight)
{
	game->ReshapeWindow(SWidth, SHeight);									
}


void update(int value)
{
	game->update(timer.getTime() - oldTime);
	glutPostRedisplay();																
	glutTimerFunc(refreshMilliseconds, update, 0);										
	oldTime = timer.getTime();
}

void processKeys(unsigned char key, int x, int y)
{

	if (key == 32)
	{
		game->SpawnCue();
	}
}

void Render()
{
	glutDisplayFunc(display);														
	glutReshapeFunc(reshape);														
	glutTimerFunc(0, update, 0);													
	initGL();																		
	glutKeyboardFunc(processKeys);
	glutMainLoop();																	

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);															
	game = new Game();
	game->Load();
	timer.startTimer();
	Render();
	
	delete game;
	return 0;
}