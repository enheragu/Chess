#include "Grafico\CoordinadorAjedrez.h"
#include <iostream>
#include "glut.h"

using namespace std;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void ControlRaton(int button, int state, int x, int y);
void createMenus();

CoordinadorAjedrez ajedrez, *pa=&ajedrez;

//GraficosAjedrez graficosAjedrez;

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100,900,-100,900,0.2,-0.2);
	//gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(ControlRaton);
	
	// crear menus!
	createMenus();

	int estado = ajedrez.getEstado();
	CoordinadorAjedrez *pb=&ajedrez;
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	
   
	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1,9,-1,9,-0.2,0.2);
	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	ajedrez.Dibuja();

	createMenus();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	//ajedrez.Tecla(key); //gestionado mediante menu con boton derecho
	glutPostRedisplay();
}

void OnTimer(int value)
{
//poner aqui el código de animacion

	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}

void ControlRaton(int button, int state, int x, int y)
{
	float w=glutGet(GLUT_WINDOW_WIDTH);
	float h=glutGet(GLUT_WINDOW_HEIGHT);
	if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		Casilla casilla;
		casilla.x = 10*(x/w-0.1);
		casilla.y= 10*((1-y/h)-0.1);
		std::cout << "Casilla:" << casilla.x << "," << casilla.y <<endl;
		ajedrez.raton(casilla);
    }

}
void processMenuEvents(int value)
{
	ajedrez.processMenuEvents((unsigned char)value);
}

void createMenus() {

	// create the menu and
	// tell glut that "processMenuEvents" will
	// handle the events
	int menu1 = glutCreateMenu(processMenuEvents);

	//add entries to our menu
	glutAddMenuEntry("Iniciar Partida", 'e');
	glutAddMenuEntry("Salir del Juego", 's');

	if (ajedrez.getEstado() == 1) // 1 = JUEGO
	{
		int menu2 = glutCreateMenu(processMenuEvents);
		
		glutAddMenuEntry ("Reiniciar partida", 'r');
		glutAddMenuEntry ("Salir del Juego", 's');
	}
	// attach the menu to the right button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
