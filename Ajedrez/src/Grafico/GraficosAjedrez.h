#pragma once
#include "grafico\Piezas.h"
#include "Logico\Tablero.h"
class GraficosAjedrez
{
private: 
	Piezas pieza;
	Tablero tablero; //tablero de la logica, este deberá ser borrado

	int x_ojo, y_ojo, z_ojo;

public:
	GraficosAjedrez(void);
	~GraficosAjedrez(void);
	
	void Inicializa();
	void dibujarDisco  (int x,float y, int r, int g, int b, float rad, float z=0.0001);
	void dibujarJaque (Casilla &c);
	void dibujarTablero ();
	void dibujarTurno (int );
	void introduzcaOrigen ();
	void introduzcaDestino ();
	void Error();
	void dibujaInicio();
	void dibujaImagenInicio();
	void introduzcaOpciones();
	/*
	void ErrorJaque();
	void jaque();
	*/

};


