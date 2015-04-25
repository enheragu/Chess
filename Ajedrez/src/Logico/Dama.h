// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Dama : public Pieza
{
public:
	Dama(int x, int y, int t);
	~Dama(void);
	//restricciones de movimiento
	void mueveDama (void);
	void comeDama (void);
};

