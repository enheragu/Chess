#pragma once
class Casilla
{
public:

	float x; //no merece la pena ponerlo privado ya que el valor va a ser
	float y; //valido siempre valga cuanto valga

	Casilla (float xv=0.0f,float yv=0.0f);
	~Casilla(void);
	//operadores sobrecargados, operaciones con vectores
	Casilla operator + (Casilla op); // suma de vectores
	Casilla operator + (float real);
	float modulo(); // modulo del vector
	float argumento(); // argumento del vector
	Casilla unitario(); // devuelve un vector unitario
	Casilla operator - (Casilla op); // resta de vectores
	float operator *(Casilla op); // producto escalar
	Casilla operator *(float); // producto por un escalar
	Casilla operator / (float);
	bool operator != (Casilla op);
};

