// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Torre : public Pieza
{
	bool movido;

public:
	Torre(void);
	~Torre(void);
	//restricciones de movimiento
	void mueveTorre (void);
	void comeTorre (void);
};

