#pragma once
class Casilla;
class Tablero
{
	static int posInicial[8][8];
public:
	Tablero(void);
	virtual ~Tablero(void);

	/*********************************************************************************************
 	 *					  Codificacion piezas				     *
	 *********************************************************************************************/
	/*
	 Blancas			Pieza			  Negras
		0			Casilla vacia			0
		1			Peon sin mover			-1
		2			Peon movido 2			-2
		3			Caballo					-3
		4			Alfil					-4
		5			Torre no movida			-5
		6			Torre movida			-6
		7			Dama					-7
		8			Rey no movida			-8
		9			Rey movido				-9
	*/

//Representación de la posición de las piezas de cada jugador
	int tablero[8][8];
	int leerCasilla(Casilla &c);
	void reset ();
};

