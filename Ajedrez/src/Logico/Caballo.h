// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Caballo : public Pieza
{
public:
	Caballo(int x, int y, int t);
	~Caballo(void);
	//restricciones de movimiento
	void mueveCaballo (void);
	void comeCaballo (void);
};

