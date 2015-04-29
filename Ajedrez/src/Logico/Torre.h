// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Torre : public Pieza
{

public:
	Torre(int x, int y, int t);
	~Torre(void);
	//restricciones de movimiento
	void mueveTorre (void);
	void comeTorre (void);
};

