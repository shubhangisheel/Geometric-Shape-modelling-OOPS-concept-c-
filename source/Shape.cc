#include "Shape.h"
#include <sstream>
#include <typeinfo>

using std::ostringstream ;
using std::endl ;

// Declaration for static member Object Counter
size_t Shape::objectCounter = 0 ;


Shape::Shape ( const string fixedName, const string variableName ) :

 		id (++objectCounter), genName (fixedName) , descName (variableName) {

}

Shape::Shape ( const Shape & rhs ) : id (++objectCounter), genName (rhs.getGenName()), descName (rhs.getDescName()) {

}

Shape & Shape::operator= ( const Shape & rhs ) {
	descName = rhs.getDescName () ;
	return *this ;
}

// String Representation of object
string Shape::toString () const {

	// Write the details of shape into an oput string stream and then return a string representation of the stream
	ostringstream representation ;

	// Sets the width for proper formatting
	representation.width (15) ;

	representation << "Shape Information" << endl ;
	representation << "-----------------" << endl ;
	
	representation 	<< std::left 
					<< "Type of this:"
					<< '\t'
					<< typeid(this).name()
					<< endl ;

	representation 	<< std::left 
					<< "Type of *this:"
					<< '\t'
					<< typeid(*this).name()
					<< endl ;

	representation 	<< std::left 
					<< "Generic name:"
					<< '\t'
					<< genName
					<< endl ;

	representation 	<< std::left 
					<< "Description:"
					<< '\t'
					<< descName
					<< endl ;

	representation.width (15) ;

	representation 	<< std::left 
					<< "id:"
					<< '\t'
					<< id
					<< endl ;

	representation 	<< std::left 
					<< "H extent:"
					<< '\t'
					<< horizontalExtent ()
					<< endl ;

	representation 	<< std::left 
					<< "V extent:"
					<< '\t'
					<< verticalExtent () 
					<< endl ;

	representation 	<< std::left 
					<< "Scr area:"
					<< '\t'
					<< screenArea ()
					<< endl ;

	representation 	<< std::left 
					<< "Geo area:"
					<< '\t'
					<< geometricArea () 
					<< endl ;

	representation 	<< std::left 
					<< "Scr perimeter:"
					<< '\t'
					<< screenPerimeter ()
					<< endl ;

	representation 	<< std::left 
					<< "Geo perimeter:"
					<< '\t'
					<< geometricPerimeter ()
					<< endl ;

	// Return String representation of Stream
	return representation.str () ;
}

ostream & operator<< ( ostream & sout, const Shape & item ) {

	// Delegates the actual work of getting the details to the toString method of item and then write the details to sout
	sout << item.toString () ;
	
	return sout ;
}