#include <Windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cmath>

#define janela_altura 800
#define janela_largura 900


void keyboard(unsigned char key, int x, int y);
void resize(GLsizei w, GLsizei h);
void display(void);

int main(int argc, char** argv) {
	glutInit(&argc, argv); //controla se o sitema operacional tem suporte a janelas
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //quantidade de buffer de cores e o padrão de cor utilizado

	glutInitWindowSize(janela_altura, janela_altura); //tamanho da janela

	//glutFullScreen(); //full screen

	glutInitWindowPosition(500, 60); //posicao inicial da janela

	glutCreateWindow("TESTE 13456"); //cria a janela

	glutKeyboardFunc(&keyboard);

	glutReshapeFunc(&resize);

	glutDisplayFunc(display);

	glutMainLoop();

	return EXIT_SUCCESS;

}


void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case
		'\x1B':
			exit(EXIT_SUCCESS);
			break;
	}
}


void resize(GLsizei w, GLsizei h) {
	if (h == 0) h = 1;

	glViewport(0, 0, w, h);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	if (w <= h)
	{
		gluOrtho2D(0, janela_altura, 0, janela_largura * h / w);
	}
	else
	{
		gluOrtho2D(0, janela_altura * h / w, 0, janela_largura);
	}

	glMatrixMode(GL_MODELVIEW);

}

void display() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);



	//glTranslatef(janela_altura / 2, janela_largura / 2, 0); //Colocar o plano cartesiano no centro da tela
	
	//gramado
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex2f(0, 0);
	glVertex2f(0, 200);
	glVertex2f(800, 200);
	glVertex2f(800, 0);
	glEnd();

	//casa
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex2f(300, 200);
	glVertex2f(300, 600);
	glVertex2f(600, 600);
	glVertex2f(600, 200);
	glEnd();

	//porta
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0);
	glVertex2f(300, 200);
	glVertex2f(300, 350);
	glVertex2f(400, 350);
	glVertex2f(400, 200);
	glEnd();

	//maçaneta
	glPointSize(10);
	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);
	glVertex2f(375, 275);
	glEnd();

	//janela
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(425, 425);
	glVertex2f(425, 475);
	glColor3f(0, 0, 1);
	glVertex2f(475, 475);
	glVertex2f(475, 425);
	glEnd();

	//telhado
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex2f(300, 600);
	glVertex2f(450, 800);
	glVertex2f(600, 600);
	glEnd();

	
	glFlush();

}