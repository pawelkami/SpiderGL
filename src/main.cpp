#include "declarations.h"

int main( int argc, char** argv )
{
	//Inicjalizacja biblioteki GLUT
	glutInit( &argc, argv );

	//Poczatkowa pozycja okna wyrazona w pikselach
	glutInitWindowPosition( 0, 0 );

	//Poczatkowy rozmiar okna wyrazony w pikselach
	glutInitWindowSize( 750, 750 );

	//Tryb wyswietlania:
	//kolory: GLUT_RGB - tryb RGB, GLUT_INDEX - kolory indeksowane
	//buforowanie: GLUT_DOUBLE - podwojne buforowanie, GLUT_SINGLE - pojedyncze buforowanie
	//GLUT_DEPTH - okno z buforem glebokosci
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );

	//Utworzenie okna
	glutCreateWindow( "SPIDER OPENGL" );

	//Rejestracja funkcji odpowiedzialnej za zmiane parametrow
	//po zmianie rozmiaru okna
	glutDisplayFunc( display );
	glutReshapeFunc( reshape );

	//Rejestracja funkcji odpowiedzialnej za obsluge 
	//klawiatury (tylko znaki ASCII)
	glutKeyboardFunc( keyPressed );

	//Rejestracja funkcji odpowiedzialnej za obsluge 
	//klawiatury (klawisze funkcyjne + strzalki + kl. specjalne)
	glutSpecialFunc( keySpecial );

	//Rejestracja funkcji odpowiedzialnej za wyswietlanie
	//zawartosci okna
	glutIdleFunc( display );

	//Nasza wlasna inicjalizacja
	init();

	//Wlaczenie przetwarzania zdarzen przez biblioteke GLUT
	glutMainLoop();

	return 0;
}