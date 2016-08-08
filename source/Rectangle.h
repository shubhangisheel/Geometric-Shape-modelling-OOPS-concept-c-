#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {

private:

	int width ;
	int height ;

public:

	Rectangle ( const int w, const int h, const string & description = "Generic Rectangle" ) ;

public:

	int getWidth () const {
		return width ;
	}

	int getHeight () const {
		return height ;
	}

	void setWidth ( int newWidth ) ;
	void setHeight ( int newHeight ) ;

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