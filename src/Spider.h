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

	// flagi mówi¹ce czy odnó¿a maj¹ siê poruszaæ do przodu czy ty³u
	bool leftSideForward;
	bool rightSideForward;

	// zmienne mówi¹ce o ile ma siê przesun¹æ dane odnó¿e
	GLfloat leftSideCount;
	GLfloat rightSideCount;

	// rysowanie poszczególnych czêœci cia³a
	void drawEyes();
	void drawBody();
	void drawLegs();

	//rysowanie czêœci lewej nogi
	void legPartsLeft();

	// rysowanie czêœci prawej nogi
	void legPartsRight();

	// do poruszania odw³okiem
	GLfloat bodyCount;	// w jakiej pozycji ma byæ odw³ok

	bool bodyUpside; // czy ma iœæ w górê czy w dó³

};

#endif