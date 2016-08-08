#include "FramedCanvas.h"

FramedCanvas::FramedCanvas ( const int width, const int height, const string & title ) 
	: Canvas ( width + 2, height + 4 ), frameTitle ( title ) {
		decorate () ;
}

void FramedCanvas::clear ( char ch ) {

	int lastCol = getw () - 1 ;
	int lastRow = geth () - 1 ;

	for ( int colClientArea = 1 ; colClientArea != lastCol ; ++colClientArea ) {

		for ( int rowClientArea = 3; rowClientArea != lastRow ; ++rowClientArea ) {
			grid [colClientArea][rowClientArea] = ch ;
		}
	}
}

void FramedCanvas::put ( const int width, const int height, const char ch ) {

	if ( width < 0 || width >= getw () - 2 || height < 0 || height >= geth () - 4 ) {
		return ;
	}

	grid [ width + 1 ][ height + 3 ] = ch ;
}

char FramedCanvas::get ( const int width, const int height ) const {

	if ( width < 0 || width >= getw () - 2 || height < 0 || height >= geth () - 4 ) {
		return ' ' ;
	}

	return grid [ width + 1 ][ height + 3 ] ;
}

void FramedCanvas::decorate () {

	int lastRow = geth () -1 ;
	int lastCol = getw () - 1 ;

	grid [0][0] = grid [0][lastRow] = grid [lastCol][0] = grid [lastCol][lastRow] = '+' ;

	for ( int col = 1 ; col != lastCol ; ++col ) {
		grid[col][0] = '-' ;
		grid[col][2] = '-' ;
		grid[col][lastRow] = '-' ;
	}

	for ( int row = 1 ; row != lastRow ; ++row ) {
		grid[0][row] = '|' ;
		grid[lastCol][row] = '|' ;
	}

	int col = 1 ;
	for ( auto c : frameTitle ) {
		if ( col == lastCol ) {
			break ;
		}
		grid[col][1] = c ;
		++col ;
	}
}