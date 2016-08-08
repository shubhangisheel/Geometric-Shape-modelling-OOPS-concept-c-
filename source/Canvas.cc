#include "Canvas.h"

using std::endl ;

Canvas::Canvas ( const int width, const int height ) : grid ( width, vector<char> (height,' ')) {

}

void Canvas::clear ( char ch ) {

	for ( auto & col : grid ) {
		for ( auto & c : col ) {
			c = ch ;
		}
	}
}

void Canvas::put ( int col, int row, char ch ) {

	if ( col < 0 || col >= getw () || row < 0 || row >= geth() ) {
		return ;
	}

	grid[col][row] = ch ;
}

char Canvas::get ( int col, int row ) const {

	if ( col < 0 || col >= getw () || row < 0 || row >= geth () ) {
		return ' ' ;
	}

	return grid [col][row] ;
}

void Canvas::decorate () {
	return ;
}

ostream & operator<< ( ostream & sout, const Canvas & item ) {

	for ( int row = 0 ; row < item.geth (); ++row ) {
		for ( int col = 0; col < item.getw() ; ++col ) {
			sout << item.Canvas::get (col,row) << " " ;
		}
		sout << endl ;
	}

	return sout ;
}