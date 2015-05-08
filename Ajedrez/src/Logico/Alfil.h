
// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Alfil : public Pieza
{


public:
	Alfil(int x, int y, int color);
	~Alfil(void);
	//restricciones de movimiento
	void mueveAlfil (struct jugada*);
	void comeAlfil (void);
};

