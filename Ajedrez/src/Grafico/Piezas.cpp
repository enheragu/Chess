#include "Piezas.h"

Piezas::Piezas(void)
{
}


Piezas::~Piezas(void)
{
}
#include <math.h>
void Piezas::dibujaPieza(int x, int y, char *tex)
{
	unsigned int image1 = OpenGL::CargaTextura(tex);
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image1);
		glDisable(GL_LIGHTING);
		glColor3ub(100, 100, 100);
		glColor3f(1, 1, 1);
		glPushMatrix();
		glTranslatef(x,y,0);
		glBegin(GL_POLYGON);
		for(float angle =0;angle<2*3.14;angle+=0.1F)
		{
			float co=cos(-angle);
			float si=sin(-angle);
			glTexCoord2d(0.5+0.49*co,0.5+0.49*si);
			glVertex3f(0.5+0.4*co,0.5+0.4*si, 0.001);
		}
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
}

void Piezas::dibujaPeonNegra(int x, int y)
{
	dibujaPieza(x,y,"Images/peon_negro.bmp");
}

void Piezas::dibujaPeonBlanca(int x, int y)
{
	dibujaPieza(x,y,"Images/peon_blanco.bmp");
}

void Piezas::dibujaAlfilNegra(int x, int y)
{
	dibujaPieza(x,y,"Images/alfil_negro.bmp");
}

void Piezas::dibujaAlfilBlanca(int x, int y)
{
	dibujaPieza(x,y,"Images/alfil_blanco.bmp");
}

void Piezas::dibujaTorreNegra(int x, int y)
{
	dibujaPieza(x,y,"Images/torre_negra.bmp");
}

void Piezas::dibujaTorreBlanca(int x, int y)
{
	dibujaPieza(x,y,"Images/torre_blanca.bmp");
}

void Piezas::dibujaCaballoNegra(int x, int y)
{
	dibujaPieza(x,y,"Images/caballo_negro.bmp");
}

void Piezas::dibujaCaballoBlanca(int x, int y)
{
	dibujaPieza(x,y,"Images/caballo_blanco.bmp");
}

void Piezas::dibujaReyNegra(int x, int y)
{
	dibujaPieza(x,y,"Images/rey_negro.bmp");
}

void Piezas::dibujaReyBlanca(int x, int y)
{
	dibujaPieza(x,y,"Images/rey_blanco.bmp");
}

void Piezas::dibujaReinaNegra(int x, int y)
{
	dibujaPieza(x,y,"Images/dama_negra.bmp");
}

void Piezas::dibujaReinaBlanca(int x, int y)
{
	dibujaPieza(x,y,"Images/dama_blanca.bmp");
}