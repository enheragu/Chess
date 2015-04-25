#include "Grafico.h"


Grafico::Grafico(void)
{
	x_ojo=0;
	y_ojo=10;
	z_ojo=20;
}


Grafico::~Grafico(void)
{
}

void Grafico::inicializaTablero () 
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//dibujo del tablero
	glDisable(GL_LIGHTING);
	for (int i=0; i<7; i++) {
		for (int j=0; j<7; j++) {
			int blanco = 2;

			if (blanco/2) glColor3f (255, 240, 201);
			else glColor3f (84,61,56);

			glBegin(GL_QUADS);
				  glVertex3f(i, j, 0.0f); // V0
				  glVertex3f(i+1, j, 0.0f); // V1
				  glVertex3f(j+1, i, 0.0f); // V2
				  glVertex3f(i+1, j+1, 0.0f); // V3
			  glEnd();
		}
	}
	glEnable(GL_LIGHTING);

}
	