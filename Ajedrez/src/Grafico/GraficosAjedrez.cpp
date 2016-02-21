#include "GraficosAjedrez.h"
#include "Logico\Tablero.h"

GraficosAjedrez::GraficosAjedrez(void)
{
}


GraficosAjedrez::~GraficosAjedrez(void)
{
}


void GraficosAjedrez::Inicializa()
{
	x_ojo=4;
	y_ojo=5;
	z_ojo=15;
	
	dibujarTablero();
}

void GraficosAjedrez::dibujarDisco (int x,float y, int r, int g, int b, float rad, float z)
{	
		glColor3f(r, g, b);
		glPushMatrix();
		glTranslatef(x,y,0);
		glBegin(GL_POLYGON);
		for(float angle =0;angle<2*3.14;angle+=0.1F)
		{
			float co=cos(-angle);
			float si=sin(-angle);
			glVertex3f(0.5+rad*co,0.5+rad*si, z);
		}
		glEnd();
		glPopMatrix();
		glEnable(GL_LIGHTING);

}
/*
void GraficosAjedrez::dibujarJaque (Casilla &c)
{
	glColor3f(255,255,0);
		glPushMatrix();
		glTranslatef(c.x,c.y,0);
		glBegin(GL_POLYGON);
		for(float angle =0 ; angle<2*3.14 ; angle+=0.5235F )
		{
			int index = 0;
			float co=cos(-angle);
			float si=sin(-angle);
			if (index % 2)
				glVertex3f(0.5+0.4*co,0.5+0.4*si, 0.0001);
			else
				glVertex3f(0.5+0.6*co,0.5+0.6*si, 0.0001);
			index ++;
		}
		glEnd();
		glPopMatrix();
		glEnable(GL_LIGHTING);
}
*/

void GraficosAjedrez::dibujarTablero()
{

	glDisable(GL_LIGHTING);
	glBegin(GL_QUADS);
		
		for(int i=0;i<8;i+=1)  
		{  
			for(int j=0;j<8;j+=1){ 
				if((i+j)%2)glColor3ub(0,0,0);
				else glColor3ub(255,255,255);
				glVertex3f(i,j,0.0);
				glVertex3f(i+1,j,0.0);
				glVertex3f(i+1,j+1,0.0);	
				glVertex3f(i,j+1,0.0);
			}
		}
	glEnd();
}

void GraficosAjedrez::dibujarTurno (int turno)
{
	if (turno == 1)
	{
		OpenGL::Print("Turno:",13,260,255,0,0);
		dibujarDisco (-1,3.5, 255,255,255,0.25);
	}
	else if (turno == -1)
	{
		OpenGL::Print("Turno:",735,260,255,0,0);
		dibujarDisco (8,3.5, 0,0,0,0.23, 0.002);
		dibujarDisco (8,3.5, 255,255,255,0.27);
	}
}


void GraficosAjedrez::introduzcaOrigen ()
{
	OpenGL::Print("Clique con el boton izquierdo la pieza que desea mover",90,10,255,0,0);
}

void GraficosAjedrez::introduzcaOpciones ()
{
	OpenGL::Print("(boton derecho para mas opciones)",90,25,255,0,0);
}

void GraficosAjedrez::introduzcaDestino ()
{
	OpenGL::Print("Clique con el boton izquierdo el destino de la pieza seleccionada",10,10,255,0,0);
}

void GraficosAjedrez::Error()
{
	OpenGL::Print("Error, movimiento incorrecto",90,560,255,0,0);
}

void GraficosAjedrez::dibujaInicio()
{
	OpenGL::Print("Ajedrez",400,0,0,0,255);
	OpenGL::Print("Pulse boton derecho para acceder a las opcciones",350,540,5,255,255);
	//OpenGL::Print("Pulse E para empezar",550,540,5,255,255);
	//OpenGL::Print("Pulse S para salir",550,560,5,255,255);
	OpenGL::Print("Enrique Heredia Aguado",550,0,25,200,255);
	OpenGL::Print("Pilar Lopez Ruescas",550,20,25,200,255);
	dibujaImagenInicio();
}

void GraficosAjedrez::dibujaImagenInicio()
{
	unsigned int image1 = OpenGL::CargaTextura("Images/Inicio.bmp");
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image1);
		glDisable(GL_LIGHTING);
		glColor3ub(100, 100, 100);
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glTexCoord2d(0.0f, 0.0f);
		glVertex3f(8, 0, 0);
		glTexCoord2d(0.0f, 1.0);
		glVertex3f(8, 8, 0);
		glTexCoord2d(1.0f, 1.0f);
		glVertex3f(0, 8, 0);
		glTexCoord2d(1.0f, 0.0f);
		glVertex3f(0, 0, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
}

/*
void GraficosAjedrez::ErrorJaque()
{
	OpenGL::Print("Movimiento no valido, rey en jaque",90,560,255,0,0);
}

void GraficosAjedrez::jaque()
{
	OpenGL::Print("Jaque al Rey",90,560,255,0,0);
}
*/