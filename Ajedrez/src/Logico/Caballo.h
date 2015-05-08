// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Caballo : public Pieza
{
public:
	Caballo(int x, int y, int color);
	~Caballo(void);
	//restricciones de movimiento
	void mueveCaballo (struct jugada*);
	void comeCaballo (void);
};

