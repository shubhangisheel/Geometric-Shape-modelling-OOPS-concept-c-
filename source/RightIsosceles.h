#ifndef RIGHT_ISOSCELES_H
#define RIGHT_ISOSCELES_H

#include "Shape.h"

class RightIsosceles : public Shape {

private:

	int height ;

public:

	RightIsosceles ( const int h, const string & description = "Generic Right Isosceles Triangle" ) ;

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