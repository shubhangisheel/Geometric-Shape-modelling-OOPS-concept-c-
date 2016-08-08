#ifndef BORDERED_CANVAS_H
#define BORDERED_CANVAS_H

#include "Canvas.h"

class BorderedCanvas : public Canvas {

public:
	BorderedCanvas ( const int width, const int height ) ;

public:

	virtual void clear ( char ch = ' ' ) ;
	virtual void put ( int col, int row, char ch = '*' ) ;
	virtual char get ( int col, int row ) const ;
	virtual void decorate () ;

} ;
#endif