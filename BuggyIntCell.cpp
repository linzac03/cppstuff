#include <iostream>
using namespace std;

/**
 * Figure 1.16: Implements the big five.
 */
class IntCell
{
  public:
    explicit IntCell( int initialValue = 0 )
      { storedValue = new int{ initialValue }; }

    int read( ) const
      { return *storedValue; }
    void write( int x )
      { *storedValue = x; }
    
  private:
    int *storedValue;
};


/*
 * Figure 1.17.
 */
int f( )
{
    IntCell a{ 2 };
    IntCell b = a;
    IntCell c;

    c = b;
    a.write( 4 );
    cout << a.read( ) << endl << b.read( ) << endl << c.read( ) << endl;
    
    return 0;
}

void intcellarr_shallow() {
	IntCell arr[8];
	IntCell* narr[8];

	int i;
	cout << "Original: ";
	for(i=0; i < 8; i++) {
		arr[i].write(i);		
		cout << arr[i].read() << (i < 7 ? ", " : "");
	}
	cout << endl;
	cout << "Shallow Copy: ";
	for(i=0; i < 8; i++) {
		narr[i] = &arr[i];		
		cout << (*narr[i]).read() << (i < 7 ? ", " : "");
	}	
	cout << endl;
}

int main( )
{
    f( );
		intcellarr_shallow();    
    return 0;
}
