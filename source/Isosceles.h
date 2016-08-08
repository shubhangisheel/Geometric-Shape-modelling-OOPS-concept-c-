#ifndef ISOSCELES_H
#define ISOSCELES_H

#include "Shape.h"

class Isosceles : public Shape {

private:

	int height ;

public:

	Isosceles ( const int h, const string & description = "Generic Isosceles Triangle" ) ;

public:

	int getHeight () const {
		return height ;
	}

	void setHeight ( const int newHeight ) ;

public:

	virtual void scale ( const int scaleFactor ) ;
	virtual void draw ( int c, int r, Canvas & canvas, char ch = '*' ) const ;

protected:

	virtual double geometricArea () const ;
	virtual double geometricPerimeter () const ;

	virtual int screenArea () const ;
	virtual int screenPerimeter () const ;

	virtual int horizontalExtent () const ;
	virtual int verticalExtent () const ;
} ;
#endif