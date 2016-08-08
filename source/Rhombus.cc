#include "Rhombus.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

using std::cerr ;
using std::endl ;

Rhombus::Rhombus ( const int d, const string & description ) : Shape ( "Rhombus", description ) {

	setDiagonal ( d ) ;
}

void Rhombus::setDiagonal ( const int newDiagonal ) {

	try {

		if ( newDiagonal < 1 ) {
			throw std::range_error ( "Invalid Diagonal for Rectangle" ) ;
		}
	}

	catch ( std::range_error err ) {
		cerr << "Program can't continue due to the following error" << endl ;
		cerr << err.what () << endl ;
		cerr << "Exiting" << endl ;
		exit (1) ;
	}

	if ( newDiagonal % 2 == 0 ) {
		diagonal = newDiagonal + 1 ;
	}

	else {
		diagonal = newDiagonal ;
	}
}

void Rhombus::scale ( const int scaleFactor ) {

	int d = diagonal + scaleFactor ;

	// Ignore the scale request if scaling makes diagonal less than 1
	if ( d >= 1 ) {
		if ( d % 2 != 0 ) {
			diagonal = d ;
			return ;
		}

		// If scaling makes diagonal even , then we need to choose the best odd value instead
		// Because rhombus cant have odd length diagonal
		// The best odd value depends on the users intent
		// If the user intended to scale down the Rhombus then best value = d - 1
		else if ( scaleFactor < 0 ) {
			if ( (d - 1) >= 1 ) {
				diagonal = d - 1 ;
			}
		}

		// If the user intended to scale up the Rhombus then best value = d + 1
		else {
			diagonal = d + 1 ;
		}
	}
}

double Rhombus::geometricArea () const {

	return ( diagonal * diagonal ) / 2 ;
}

double Rhombus::geometricPerimeter () const {

	return ( 2 * sqrt (2) ) * diagonal ;
}

int Rhombus::screenArea () const {

	int n = diagonal / 2 ;

	return 2 * n * ( n + 1 ) + 1 ;
}

int Rhombus::screenPerimeter () const {

	return 2 * ( diagonal - 1 ) ;
}

int Rhombus::horizontalExtent () const {

	return diagonal ;
}

int Rhombus::verticalExtent () const {

	return diagonal ;
}

void Rhombus::draw ( int c, int r, Canvas & canvas, char ch ) const {

	int horizontalExtentOnCanvas = c + horizontalExtent () ;
	int i, j ;
	i = j = horizontalExtent () / 2  + c ;

	while ( j != horizontalExtentOnCanvas ) {

		for ( int k = i ; k != j + 1 ; ++k ) {
			canvas.put (k,r,ch) ;
		}

		++r ;
		--i ;
		++j ;
	}

	i = i + 2 ;
	j = j - 2 ;

	while ( i != j ) {

		for ( int k = i ; k != j + 1 ; ++k ) {
			canvas.put (k,r,ch) ;
		}
		++r ;
		++i ;
		--j ;	
	}

	canvas.put (i,r,ch) ;
}