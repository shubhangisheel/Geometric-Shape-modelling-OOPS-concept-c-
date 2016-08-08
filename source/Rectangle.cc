#include "Rectangle.h"
#include <stdexcept>
#include <iostream>

using std::cout ;
using std::cerr ;
using std::endl ;

Rectangle::Rectangle ( const int w, const int h, const string & description ) : Shape( "Rectangle", description ) {
	setWidth ( w ) ;
	setHeight ( h ) ;
}

void Rectangle::setWidth ( int newWidth ) {

	try {

		if ( newWidth <  1 ) {
			throw std::range_error ( "Invalid Width for Rectangle" ) ;
		}
	}

	catch ( std::range_error err ) {
		cerr << "Program can't continue due to the following error" << endl ;
		cerr << err.what () << endl ;
		cerr << "Exiting" << endl ;
		exit (1) ;
	}
	
	width = newWidth ;
}

void Rectangle::setHeight ( int newHeight ) {

	try {

		if ( newHeight <  1 ) {
			throw std::range_error ( "Invalid height for Rectangle" ) ;
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

void Rectangle::scale ( const int scaleFactor ) {

	if ( (width + scaleFactor) >= 1 && (height + scaleFactor) >= 1 ) {

		width += scaleFactor ;
		height += scaleFactor ; 
	}
}

double Rectangle::geometricArea () const {

	return height * width ;
}

double Rectangle::geometricPerimeter () const {

	return 2 * ( height + width ) ;
}

int Rectangle::screenArea () const {

	return height * width ;
}

int Rectangle::screenPerimeter () const {

	return 2 * ( height + width ) - 4 ;
}

int Rectangle::horizontalExtent () const {

	return width ;
}

int Rectangle::verticalExtent () const {

	return height ;
}

void Rectangle::draw ( int c, int r, Canvas & canvas, char ch ) const {

	int drawingWidth = c + horizontalExtent () ;
	int drawingHeight = r + verticalExtent () ;
	
	for ( int i = c ; i != drawingWidth ; ++i ) {
		for ( int j = r ; j != drawingHeight ; ++j ) {
			canvas.put (i,j,ch) ;
		}
	}
}
