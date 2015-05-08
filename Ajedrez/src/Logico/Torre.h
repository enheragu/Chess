// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Torre : public Pieza
{

public:
	Torre(int x, int y, int color);
	~Torre(void);
	//restricciones de movimiento
	void mueveTorre (struct jugada*);
	void comeTorre (void);
};

