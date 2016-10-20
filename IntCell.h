#ifndef IntCell_H
#define IntCell_H
#include <ostream>
/**
 * A class for simulating an integer memory cell.
 */
class IntCell
{
  public:
    explicit IntCell( int initialValue = 0 );
    int read( ) const;
    void write( int x );
    IntCell operator+ ( ); 
  	IntCell operator- ( );
		friend std::ostream& operator<< (std::ostream& os, const IntCell& x);
	private:
    int storedValue;
};

#endif
