#include "Isosceles.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

using std::cerr ;
using std::endl ;

Isosceles::Isosceles ( const int h, const string & description ) : Shape ( "Isosceles", description ) {

	setHeight ( h ) ;
}

void Isosceles::setHeight ( const int newHeight ) {

	try {
		if ( newHeight < 1 ) {
			throw std::range_error ( "Invalid Height for Isosceles Triangle" ) ;
		}
	}

	catch ( std::range_error err ) {
		cerr << "Program can't continue due to the following error" << endl ;
		cerr << err.what () << endl ;
		cerr << "Exiting" << endl ;
		exit (1) ;
	}

	height = newHeight ;
}

void Isosceles::scale ( const int scaleFactor ) {

	int h = height + scaleFactor ;
	if ( h >= 1 ) {
		height = h ;
	}
}

double Isosceles::geometricArea () const {

	int base = 2 * height - 1 ;

	return (height * base) / 2 ;
} 

double Isosceles::geometricPerimeter () const {

	int base = 2 * height - 1 ;
	double temp = (0.25 * base * base) + (height * height) ;

	return base + 2 * sqrt ( temp ) ;
}

int Isosceles::screenArea () const {

	return height * height ;
}

int Isosceles::screenPerimeter () const {

	return 4 * ( height - 1 ) ;
}

int Isosceles::horizontalExtent () const {

	int base = 2 * height - 1 ;
	return base ;
}

int Isosceles::verticalExtent () const {

	return height ;
}

void Isosceles::draw ( int c, int r, Canvas & canvas, char ch ) const {

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
}
