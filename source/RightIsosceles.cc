#include "RightIsosceles.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

using std::cerr ;
using std::endl ;

RightIsosceles::RightIsosceles ( const int h, const string & description ) : Shape ( "Right Isosceles", description ) {

	setHeight ( h ) ;
}

void RightIsosceles::setHeight ( const int newHeight ) {

	try {
		if ( newHeight < 1 ) {
			throw std::range_error ( "Invalid Height for Right Isosceles Triangle" ) ;
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

void RightIsosceles::scale ( const int scaleFactor ) {

	int h = height + scaleFactor ;
	if ( h >= 1 ) {
		height = h ;		
	}
}

double RightIsosceles::geometricArea () const {

	return ( height * height ) / 2 ;
}

double RightIsosceles::geometricPerimeter () const {

	return ( 2 + sqrt (2) ) * height ;
}

int RightIsosceles::screenArea () const {

	return height * ( height + 1 ) / 2 ;
}

int RightIsosceles::screenPerimeter () const {

	return 3 * ( height - 1 ) ;
}

int RightIsosceles::horizontalExtent () const {

	return height ;
}

int RightIsosceles::verticalExtent () const {

	return height ;
}

void RightIsosceles::draw ( int c, int r, Canvas & canvas, char ch ) const {

	int horizontalExtentOnCanvas = c + horizontalExtent () ;
	int verticalExtentOnCanvas = r + verticalExtent () ;

	for ( int i = c ; i != horizontalExtentOnCanvas ; ++i ) {

		for ( int j = r ; j != verticalExtentOnCanvas ; ++j ) {
			canvas.put (i,j,ch) ;
		}
		++r ;
	}
}
