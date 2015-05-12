#pragma once

#include "Tablero.h"

enum jugador {BLANCAS=0, NEGRAS};
enum pieza {C_VACIA=0, PEON_SIN_MOVER, PEON_MOVIDO, CABALLO, ALFIL, TORRE_NO_MOVIDA, TORRE_MOVIDA, DAMA, REY_NO_MOVIDO, REY_MOVIDO, C_PROHIBIDA=255};

struct casilla{
	int x;
	int y;
};

 struct jugada{
	 casilla origen;
	 casilla destino;
 };

class Pieza
{
protected:
	int tipo;
	jugada jugadaPieza;
	Tablero* punteroTablero;
	int color; //1 blancas, -1 negras
	static int numJugadas;

public:
	
	Pieza(int x, int y, int t, int color);
	~Pieza(void);

	jugada* generador();
	//escribe la pieza en el tablero se le
	//pasa la posicion final de la pieza y la inicial
	void escribirPosicion(struct jugada *);
	//lee la casilla del tablero y devuelve que hay en ella
	int leerCasilla (struct jugada *);
	void pedirDestino (int x, int y);
	//se le pasa la casilla de la pieza que queremos mover, lee 
	//la casilla y llama a la pieza correspondiente
	virtual void moverPieza (struct jugada *);
};

