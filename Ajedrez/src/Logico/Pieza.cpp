#include "Pieza.h"



Pieza::Pieza(int x, int y, int t)
{
	casillaActual.x = x;
	casillaActual.y = y;
	tipo = t;
}


Pieza::~Pieza(void)
{
}

void moverRecto ()
{

}
void moverDiagonal ()
{

}
//evalua si el destino está ocupado o no
bool evaluarDestino ()
{

}
//leer los mapas para ver que pieza hay en una casilla
bool evaluarPieza ()
{
	if (Situacion::jugador)
		recorrerPosicion = &posPeonesNegras;
	else recorrerPosicion = &posPeonesBlancas;

	//avanza uno en la memoria si no encuentra el 1 que identifica que hay pieza
	while (!&recorrerPosicion)
		recorrerPosicion++;

}
//si el destino esta ocupado se comprueba si la pieza es propia o es contraria
bool evaluarBN ()
{

}
//evaluar que no hay choques en la trayectoria
bool evaluarTrayectoria ()
{

}
//evalua si la posicion a la que se quiere desplazar se encuentra "atacada" por alguna pieza contraria, 
//o defendida por una pieza "aliada"
bool evaluarVulnerabilidad ()
{

}