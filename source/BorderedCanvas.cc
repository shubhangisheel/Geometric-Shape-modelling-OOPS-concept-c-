#include "BorderedCanvas.h"

BorderedCanvas::BorderedCanvas ( const int width, const int height ) : Canvas ( width + 2, height + 2 ) {

	decorate () ;
}

void BorderedCanvas::clear ( char ch ) {

	int lastRow = geth () -1 ;
	int lastCol = getw () - 1 ;

	for ( int i = 1 ; i != lastCol ; ++i ) {
		
		for ( int j = 1 ; j != lastRow ; ++j ) {
			grid [i][j] = ch ;
		}
	
	}
}

void BorderedCanvas::put ( const int col, const int row, char ch ) {

	if ( col < 0 || col >= getw () - 2 || row < 0 || row >= geth () - 2 ) {
		return ;
	}

	grid [col + 1][row + 1] = ch ;
}

char BorderedCanvas::get ( const int col, const int row ) const {

	if ( col < 0 || col >= getw () - 2 || row < 0 || row >= geth () - 2 ) {
		return ' ';
	}

	return grid [col + 1][row + 1] ;
}

void BorderedCanvas::decorate () {

	int lastRow = geth () -1 ;
	int lastCol = getw () - 1 ;

	grid [0][0] = grid [0][lastRow] = grid [lastCol][0] = grid [lastCol][lastRow] = '+' ;

	for ( int i = 1 ; i != lastCol ; ++i ) {
		grid[i][0] = '-' ;
		grid[i][lastRow] = '-' ;
	}

	for ( int j = 1 ; j != lastRow ; ++j ) {
		grid[0][j] = '|' ;
		grid[lastCol][j] = '|' ;
	}
}