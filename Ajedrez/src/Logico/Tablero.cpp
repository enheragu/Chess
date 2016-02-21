#include "Tablero.h"
#include "Comun\Casilla.h"


/******************************************************************************************************************
 *		 	  Inicialización tablero: piezas en posicion inicial 					  *
 ******************************************************************************************************************/
int Tablero::posInicial[8][8]={ {5,3,4,8,7,4,3,5} , {1,1,1,1,1,1,1,1} , {0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0},
						  {0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0} , {-1,-1,-1,-1,-1,-1,-1,-1} , {-5,-3,-4,-8,-7,-4,-3,-5} };
Tablero::Tablero(void)
{
	
	
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			tablero[i][j] = posInicial[i][j];
		}
	}
}
int Tablero::leerCasilla(Casilla &c){
  return tablero[c.x][c.y];
}


Tablero::~Tablero(void)
{
}

void Tablero::reset()
{
	
	
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			tablero[i][j] = posInicial[i][j];
		}
	}
}