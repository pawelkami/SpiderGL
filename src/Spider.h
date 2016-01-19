#ifndef SPIDER_H
#define SPIDER_H

#include "declarations.h"

class Spider
{
public:
	Spider();
	Spider( GLfloat skinColor[], GLfloat eyesColor[] );
	void changeRotation(int change);
	void move( GLfloat x, GLfloat y, GLfloat z );
	void drawSpider();
	void moveLeftLegs();
	void moveRightLegs();
	void moveBody();
	GLfloat getRotation() const;
	GLfloat getX() const;
	GLfloat getY() const;
	GLfloat getZ() const;


private:
	GLfloat eyes[4];
	GLfloat skin[4];
	GLfloat moveX;
	GLfloat moveY;
	GLfloat moveZ;
	GLfloat rotation;

	// flagi m�wi�ce czy odn�a maj� si� porusza� do przodu czy ty�u
	bool leftSideForward;
	bool rightSideForward;

	// zmienne m�wi�ce o ile ma si� przesun�� dane odn�e
	GLfloat leftSideCount;
	GLfloat rightSideCount;

	// rysowanie poszczeg�lnych cz�ci cia�a
	void drawEyes();
	void drawBody();
	void drawLegs();

	//rysowanie cz�ci lewej nogi
	void legPartsLeft();

	// rysowanie cz�ci prawej nogi
	void legPartsRight();

	// do poruszania odw�okiem
	GLfloat bodyCount;	// w jakiej pozycji ma by� odw�ok

	bool bodyUpside; // czy ma i�� w g�r� czy w d�

};

#endif