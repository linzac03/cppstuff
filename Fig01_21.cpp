#include <iostream>
#include <string>
using namespace std;


/**
 * A class for simulating a memory cell.
 */
template <typename Object>
class MemoryCell
{
  public:
    explicit MemoryCell( const Object & initialValue = Object{ } )
      : storedValue{ initialValue } { }
    const Object & read( ) const
      { return storedValue; }
    void write( const Object & x )
      { storedValue = x; }	
	  friend inline bool operator< ( const MemoryCell & lhs, const MemoryCell & rhs ) 
			{	return lhs.storedValue < rhs.storedValue; }
		friend inline bool operator<= ( const MemoryCell & lhs, const MemoryCell & rhs ) 
			{	return lhs.storedValue <= rhs.storedValue; }
		friend inline bool operator== (const MemoryCell & lhs, const MemoryCell & rhs ) 
			{	return lhs.storedValue == rhs.storedValue; }
		friend inline bool operator!= (const MemoryCell & lhs, const MemoryCell & rhs ) 
			{	return lhs.read() != rhs.read(); }
		friend ostream& operator<< ( ostream & lhs, const MemoryCell & rhs ){	
			lhs << rhs.storedValue; 
			return lhs;	
		}
		ostream& operator<< ( ostream & lhs ) 
			{	return lhs << storedValue; }
	private:
    Object storedValue;
};

int main( )
{
    MemoryCell<int>    m1;
    MemoryCell<int>    m2;
    MemoryCell<string> m3{ "hello" };
		MemoryCell<bool> 	 m4;
		m1.write(23);
		m2.write(27);
		m3.write(m3.read() + " worls");
		cout << m3 << endl;
		cout << "m1: " << m1 << endl; 
		cout << "m2: " << m2 << endl;
		m4.write(m1 == m2);	
    cout << "== : " << m4 << endl;
		m4.write(m1 != m2);	
    cout << "!= : " << m4 << endl;
		m4.write(m1 <= m2);	
    cout << "<= : " << m4 << endl;
		m4.write(m1 < m2);	
    cout << "< : ";
		m4.operator<<(cout);
		cout << endl;

    return 0;
}
