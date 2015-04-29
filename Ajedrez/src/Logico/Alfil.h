
// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Alfil : public Pieza
{


public:
	Alfil(int x, int y, int t);
	~Alfil(void);
	//restricciones de movimiento
	void mueveAlfil (void);
	void comeAlfil (void);
};

