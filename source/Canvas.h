#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <ostream>

using std::ostream ;
using std::vector ;

class Canvas {

protected:

	// Inner vector represents the Height of the grid 
	// The containing vector (outer vector) represents the Width of the grid
	vector < vector <char> > grid ;

public:

	Canvas ( const int width, const int height ) ;
	virtual ~Canvas () = default ;

public:

	int geth () const {

		return grid[0].size () ;
	}

	int getw () const {

		return grid.size () ;
	}

public:

	virtual void clear ( char ch = ' ' ) ;
	virtual void put ( int col, int row, char ch = '*' ) ;
	virtual char get ( int col, int row ) const ;
	virtual void decorate () ;

} ;

ostream & operator<< ( ostream & sout, const Canvas & item ) ;
#endif