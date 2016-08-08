#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Shape.h"

class Rhombus : public Shape {

private:

	int diagonal ;

public:

	Rhombus ( const int d, const string & description = "Generic Rhombus" ) ;

public:

	int getDiagonal () const {
		return diagonal ;
	}

	void setDiagonal ( const int newDiagonal ) ;

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