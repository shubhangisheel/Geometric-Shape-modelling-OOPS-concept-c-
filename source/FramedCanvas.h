#ifndef FRAMED_CANVAS_H
#define FRAMED_CANVAS_H

#include "Canvas.h"
#include <string>

using std::string ;

class FramedCanvas : public Canvas {

private:

	// Stores the title of the canvas
	string frameTitle ;

public:

	FramedCanvas ( const int width, const int height, const string & title = "A framed canvas" ) ;

public:

	virtual void clear ( char ch = ' ' ) ;
	virtual void put ( int col, int row, char ch = '*' ) ;
	virtual char get ( int col, int row ) const ;
	virtual void decorate () ;

} ;
#endif