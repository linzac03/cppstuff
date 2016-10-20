#include "IntCell.h"
#include <iostream>
/**
 * Construct the IntCell with initialValue
 */
IntCell::IntCell( int initialValue ) : storedValue{ initialValue }
{
}

/**
 * Return the stored value.
 */
int IntCell::read( ) const
{
    return storedValue;
}

/**
 * Store x.
 */
void IntCell::write( int x )
{
    storedValue = x;
}

IntCell operator+ (IntCell x, IntCell y) {
	x.write(x.read() + y.read());
	return x;
}

IntCell operator+ (IntCell x, int y) {
	IntCell n;
	n.write(x.read() + y);
	return n;
}

IntCell operator- (IntCell x, IntCell y) {
	x.write(x.read() - y.read());
	return x;
}

IntCell operator- (IntCell x, int y) {
	IntCell n;
	n.write(x.read() - y);
	return n;
}

std::ostream& operator<< (std::ostream& os, const IntCell& x) {
	os << x.read();
	return os;
}
