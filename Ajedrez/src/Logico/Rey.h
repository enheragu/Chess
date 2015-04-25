// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Rey : public Pieza
{
	bool movido;

public:
	Rey(int x, int y, int t);
	~Rey(void);
	//restricciones de movimiento
	void mueveRey (void);
	void comeRey (void);
	void enrocar (bool movido);
};



