#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <ostream>
#include "Canvas.h"

using std::string ;
using std::ostream ;

class Shape {

private:

	const unsigned id ;
	const string genName ;
	string descName ;

	// objectCounter - A counter that increments and intializes id, everytime a new shape is created
	static size_t objectCounter ;

public:

	Shape ( const string fixedName, const string variableName ) ;

	// Copy constructin of a Shape should not copy the ID of the shape. Every shape should have unique ID
	// User defined Copy constructor handles this
	Shape ( const Shape & rhs ) ;
	Shape & operator= ( const Shape & rhs ) ;

	// Virtual destructor provides user with the flexibility to create shapes dynamically
	// Because the destructor is virtual it will always destroy the object pointed to by pointer or reference.
	virtual ~Shape () = default ;

public:

	unsigned getID () const {
		return id ;
	}

	string getGenName () const {
		return genName ;
	}

	string getDescName () const {
		return descName ;
	}

	void setDescName ( string newDescName ) {
		descName = newDescName ;
	}

	string toString  () const ;

public:

	virtual void scale ( const int scaleFactor ) = 0 ;
	virtual void draw ( int c, int r, Canvas & canvas, char ch = '*' ) const = 0 ;

protected:

	virtual double geometricArea () const = 0 ;
	virtual double geometricPerimeter () const = 0 ;

	virtual int screenArea () const = 0 ;
	virtual int screenPerimeter () const = 0 ;

	virtual int horizontalExtent () const = 0 ;
	virtual int verticalExtent () const = 0 ;
} ;

ostream & operator<< ( ostream & sout, const Shape & item ) ;

#endif