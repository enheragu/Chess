#pragma once

#include "glut.h"

class Grafico
{
public:
	float x_ojo;
	float y_ojo;
	float z_ojo;

	Grafico(void);
	~Grafico(void);

	void inicializaTablero (void);
	void dibujarPiezas (void);
};

