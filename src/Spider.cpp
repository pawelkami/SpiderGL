#include "Spider.h"

Spider::Spider()
{
	eyes[0] = eyes[1] = eyes[2] = 0.0;
	eyes[3] = 1.0;

	skin[0] = 0.485;
	skin[1] = 0.325;
	skin[2] = 0.19;
	skin[3] = 1.2;

	moveX = 0;
	moveY = 0;
	moveZ = 0;
	bodyCount = 15;
	bodyUpside = true;
	rotation = 45;

	leftSideCount = 0.0;
	rightSideCount = 0.0;
	leftSideForward = true;
	rightSideForward = false;
}

Spider::Spider( GLfloat skinColor[], GLfloat eyesColor[] )
{
	memcpy( skin, skinColor, 4 * sizeof(GLfloat) );
	memcpy( eyes, eyesColor, 4 * sizeof( GLfloat ) );
	moveX = 0;
	moveY = 0;
	moveZ = 0;
	bodyCount = 15;
	bodyUpside = true;
	rotation = 45;

	leftSideCount = 0.0;
	rightSideCount = 0.0;
	leftSideForward = true;
	rightSideForward = false;
}

void Spider::changeRotation( int change )
{
	rotation += change;
}

void Spider::move( GLfloat x, GLfloat y, GLfloat z )
{
	moveX += x;
	moveY += y;
	moveZ += z;
}

GLfloat Spider::getRotation() const
{
	return rotation;
}

GLfloat Spider::getX() const
{
	return moveX;
}


GLfloat Spider::getY() const
{
	return moveY;
}

GLfloat Spider::getZ() const
{
	return moveZ;
}


void Spider::drawBody()
{
	//ty³ odw³oku
	glPushMatrix();
		glTranslatef( 0.0, bodyCount/30.0-0.5, 0.0 );
		glRotatef( bodyCount, 0, 0, 1 );
		glScalef( 2.0, 0.9, 1.2 );
		glutSolidSphere( 1.0, 100, 100 );
	glPopMatrix();

	//przód odw³oku
	glPushMatrix();
		glTranslatef( -2.6, -0.5, 0.0 );
		glScalef( 1.7, 0.8, 1 );
		glutSolidSphere( 1.0, 100, 100 );
	glPopMatrix();
}

void Spider::drawEyes()
{
	GLfloat eyes[] = { 0.0, 0.0, 0.0, 1.0 };
	glPushMatrix();
		glMaterialfv( GL_FRONT, GL_DIFFUSE, eyes );
		glPushMatrix();
			glTranslatef( -3.94, -0.05, -0.2 );
			glutSolidSphere( 0.06, 10, 10 );
		glPopMatrix();

		glPushMatrix();
			glTranslatef( -3.94, -0.03, 0.0 );
			glutSolidSphere( 0.06, 10, 10 );
		glPopMatrix();

		glPushMatrix();
			glTranslatef( -3.94, -0.05, 0.2 );
			glutSolidSphere( 0.06, 10, 10 );
		glPopMatrix();

		glPushMatrix();
			glTranslatef( -4.03, -0.08, 0.1 );
			glutSolidSphere( 0.06, 10, 10 );
		glPopMatrix();

		glPushMatrix();
			glTranslatef( -4.03, -0.08, -0.1 );
			glutSolidSphere( 0.06, 10, 10 );
		glPopMatrix();

	glPopMatrix();
}

void Spider::legPartsLeft()
{
	glPushMatrix();
		glTranslatef( -0.5, 0.0, 0.0 );
		glutSolidSphere( 0.1, 10, 10 );

		glPushMatrix();
			glTranslatef( 0.22, -0.6, 0.0 );
			glRotatef( 110, 0, 0, 1 );
			glScalef( 3.7, 0.2, 0.2 );
			glutSolidSphere( 0.2, 50, 50 );
		glPopMatrix();
	glPopMatrix();

}

void Spider::legPartsRight()
{
	glPushMatrix();
	glTranslatef( 0.5, 0.0, 0.0 );
	glutSolidSphere( 0.1, 10, 10 );

		glPushMatrix();
			glTranslatef( -0.22, -0.6, 0.0 );
			glRotatef( -110, 0, 0, 1 );
			glScalef( 3.7, 0.2, 0.2 );
			glutSolidSphere( 0.2, 50, 50 );
		glPopMatrix();
	glPopMatrix();
}

void Spider::drawLegs()
{
	// nogi przednie
	// lewa
	glPushMatrix();
		glTranslatef( -3.4, -0.2, 0.8 );
		glRotatef( 80.0 + leftSideCount, 0, 1, 0 );
		glTranslatef( -0.5, 0.0, 0.0 );
		glRotatef( -30, 0, 0, 1 );

		glPushMatrix();
			glScalef( 3, 0.4, 0.4 );
			glutSolidSphere( 0.2, 50, 50 );
		glPopMatrix();
		legPartsLeft();
	glPopMatrix();

	// prawa
	glPushMatrix();
		glTranslatef( -3.4, -0.2, -0.8 );
		glRotatef( 80.0 + rightSideCount, 0, 1, 0 );
		glTranslatef( 0.5, 0.0, 0.0 );

		glRotatef( 30, 0, 0, 1 );

		glPushMatrix();
			glScalef( 3, 0.4, 0.4 );
			glutSolidSphere( 0.2, 50, 50 );
		glPopMatrix();
		legPartsRight();
	glPopMatrix();

	// nogi przednie œrodkowe
	// lewa
	glPushMatrix();
		glTranslatef( -2.8, -0.2, 0.8 );
		glRotatef( 80.0 + rightSideCount, 0, 1, 0 );
		glTranslatef( -0.5, 0.0, 0.0 );

		glRotatef( -30, 0, 0, 1 );

		glPushMatrix();
			glScalef( 3, 0.4, 0.4 );
			glutSolidSphere( 0.2, 50, 50 );
		glPopMatrix();
		legPartsLeft();
	glPopMatrix();

	// prawa
	glPushMatrix();
		glTranslatef( -2.8, -0.2, -0.8 );
		glRotatef( 80.0 + leftSideCount, 0, 1, 0 );
		glTranslatef( 0.5, 0.0, 0.0 );

		glRotatef( 30, 0, 0, 1 );

		glPushMatrix();
			glScalef( 3, 0.4, 0.4 );
			glutSolidSphere( 0.2, 50, 50 );
		glPopMatrix();
		legPartsRight();
	glPopMatrix();

	// nogi tylne œrodkowe
	// lewa
	glPushMatrix();
		glTranslatef( -2.2, -0.2, 0.8 );
		glRotatef( 80.0 + leftSideCount, 0, 1, 0 );
		glTranslatef( -0.5, 0.0, 0.0 );
		glRotatef( -30, 0, 0, 1 );

		glPushMatrix();
			glScalef( 3, 0.4, 0.4 );
			glutSolidSphere( 0.2, 50, 50 );
		glPopMatrix();
		legPartsLeft();
	glPopMatrix();

	// prawa
	glPushMatrix();
		glTranslatef( -2.2, -0.2, -0.8 );
		glRotatef( 80.0 + rightSideCount, 0, 1, 0 );
		glTranslatef( 0.5, 0.0, 0.0 );
		glRotatef( 30, 0, 0, 1 );

		glPushMatrix();
			glScalef( 3, 0.4, 0.4 );
			glutSolidSphere( 0.2, 50, 50 );
		glPopMatrix();
		legPartsRight();
	glPopMatrix();


	// nogi tylne
	// lewa
	glPushMatrix();
		glTranslatef( -1.5, -0.2, 0.8 );
		glRotatef( 80.0 + rightSideCount, 0, 1, 0 );
		glTranslatef( -0.5, 0.0, 0.0 );
		glRotatef( -30, 0, 0, 1 );

		glPushMatrix();
			glScalef( 3, 0.4, 0.4 );
			glutSolidSphere( 0.2, 50, 50 );
		glPopMatrix();
		legPartsLeft();
	glPopMatrix();

	// prawa
	glPushMatrix();
		glTranslatef( -1.5, -0.2, -0.8 );
		glRotatef( 80.0 + leftSideCount, 0, 1, 0 );
		glTranslatef( 0.5, 0.0, 0.0 );
		glRotatef( 30, 0, 0, 1 );

		glPushMatrix();
			glScalef( 3, 0.4, 0.4 );
			glutSolidSphere( 0.2, 50, 50 );
		glPopMatrix();
		legPartsRight();
	glPopMatrix();
}

void Spider::moveLeftLegs()
{
	if ( leftSideForward )
	{
		leftSideCount += 3;
		if ( leftSideCount >= 18 )
			leftSideForward = false;
	}
	else
	{
		leftSideCount -= 3;
		if ( leftSideCount <= -18 )
			leftSideForward = true;
	}
}

void Spider::moveRightLegs()
{
	if ( rightSideForward )
	{
		rightSideCount += 3;
		if ( rightSideCount >= 18 )
			rightSideForward = false;
	}
	else
	{
		rightSideCount -= 3;
		if ( rightSideCount <= -18 )
			rightSideForward = true;
	}
}

void Spider::moveBody()
{
	if ( bodyUpside )
	{
		bodyCount += 1;
		if ( bodyCount >= 25 )
			bodyUpside = false;
	}
	else
	{
		bodyCount -= 1;
		if ( bodyCount <= 15 )
			bodyUpside = true;
	}
}


void Spider::drawSpider()
{
	glPushMatrix();
		glTranslatef( moveX + 0.2, -1.0, moveZ - 10 );
		glRotatef( rotation, 0, 1, 0 );
		glMaterialfv( GL_FRONT, GL_DIFFUSE, skin );

		drawBody();
		drawEyes();
		drawLegs();
	glPopMatrix();
}
