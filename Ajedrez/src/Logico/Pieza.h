#pragma once

#include "Logico\Comun\Casilla.h"

/**********************************************************************************
 *		 Alias piezas/turnos/coordenadas para ajedrez			  *
 **********************************************************************************/
enum jugador {BLANCAS=1, NEGRAS=-1};
enum pieza {C_VACIA=0, PEON_SIN_MOVER, PEON_MOVIDO, CABALLO, ALFIL, TORRE_NO_MOVIDA, TORRE_MOVIDA, DAMA, REY_NO_MOVIDO, REY_MOVIDO};

 struct jugada{
	 Casilla origen;
	 Casilla destino; 
 };

class Tablero;

/**********************************************************************************
 *			  Clase base de todas las Piezas	 		  *
 **********************************************************************************/

class Pieza
{
public:
	Pieza(void);
	virtual ~Pieza(void);
	/* devuelve un 1 si permite e movimiento y un 0 si no se permite,
	evalua  la pieza en destino para ver si mueve o no*/
	virtual bool mover (struct jugada &);
	void sobreescribirPosicion (struct jugada  &);
	void escribirPosicion (Casilla & , int);
	//devuelve un 1 si no hay colision y un 0 si hay alguna pieza
	bool comprobarColision (struct jugada &);
	virtual int setTipo (int turno){return 0;}
	int leerCasilla (Casilla &);
	int getTurno ();
	void deshacerMovimiento (struct jugada  &);

	jugada jugadaPieza;

	static Tablero * punteroTablero;
};

