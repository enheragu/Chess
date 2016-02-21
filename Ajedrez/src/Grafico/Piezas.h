#pragma once
#include "Logico\Comun\Casilla.h"
#include "glut.h"
#include "Grafico\OpenGL.h"

class Piezas
{

public:
	Piezas(void);
	~Piezas(void);

	void dibujaPeonNegra(int x, int y);
	void dibujaPeonBlanca(int x, int y);
	void dibujaAlfilNegra(int x, int y);
	void dibujaAlfilBlanca(int x, int y);
	void dibujaTorreNegra(int x, int y);
	void dibujaTorreBlanca(int x, int y);
	void dibujaCaballoNegra(int x, int y);
	void dibujaCaballoBlanca(int x, int y);
	void dibujaReyNegra(int x, int y);
	void dibujaReyBlanca(int x, int y);
	void dibujaReinaNegra(int x, int y);
	void dibujaReinaBlanca(int x, int y);
	void dibujaPieza(int x, int y, char *tex);
};

