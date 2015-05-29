#pragma once

#include "LogicaAjedrez.h"
#include "Comun\Casilla.h"

enum jugador {BLANCAS=1, NEGRAS=-1};
enum pieza {C_VACIA=0, PEON_SIN_MOVER, PEON_MOVIDO, CABALLO, ALFIL, TORRE_NO_MOVIDA, TORRE_MOVIDA, DAMA, REY_NO_MOVIDO, REY_MOVIDO};
enum coordenada_horizontal {A=0, B, C, D, E, F, G, H};


 struct jugada{
	 Casilla origen;
	 Casilla destino;
 };


class Pieza
{
public:
	Pieza(void);
	virtual ~Pieza(void);
	/* devuelve un 1 si permite e movimiento y un 0 si no se permite,
	evalua  la pieza en destino para ver si mueve o no*/
	virtual bool mover (struct jugada *);
	void sobreescribirPosicion (struct jugada  *);
	//devuelve un 1 si no hay colision y un 0 si hay alguna pieza
	bool comprobarColision (struct jugada *);
	virtual int setTipo (int turno);

	jugada jugadaPieza;
	Tablero* punteroTablero;
	static int numJugadas;

	int leerCasilla(struct Casilla *);
	int Pieza::getTurno();

	static Tablero * punteroTablero;
};

