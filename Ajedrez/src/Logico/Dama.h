// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Dama : public Pieza
{
public:
	Dama(void);
	~Dama(void);
	//restricciones de movimiento
	void mueveDama (void);
	void comeDama (void);
};

