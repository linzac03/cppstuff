#include <iostream> 
#include "IntCell.cpp"

using namespace std;

int one;
int two;
int three;
int* mini = 0;
int* maxi = 0;
int mid;

int findmid(int x, int y, int z) {
	if (x != *maxi && x != *mini) return x;
	if (y != *maxi && y != *mini) return y;
	if (z != *maxi && z != *mini) return z;
}

void threenums() {
	cout << "Enter a three numbers: \n" << "1) ";
	cin >> one;
	cout << "2) ";
	cin >> two;
	maxi = one > two ? &one : &two;
	mini = one > two ? &two : &one;
	cout << "3) ";
	cin >> three;
	maxi = *maxi > three ? maxi : &three;
	mini = *mini > three ? &three : mini;
	mid = findmid(one, two, three);
	
	cout << "Max: " << *maxi << endl;
	cout << "Min: " << *mini << endl;
	cout << "Inorder: " << *mini << mid << *maxi << endl;	
	cout << "Reverse: " << *maxi << mid << *mini << endl;	
	cout << "Avg: "	<< ( (one + two + three) / 3 ) << endl;
}

void intcellarr_deep() {
	IntCell arr[8];
	IntCell narr[8];
	
	int i;
	cout << "Original: ";
	for (i=0; i < 8; i++) {
		arr[i].write(i);
		cout << arr[i] << (i < 7 ? ", " : "");
	}
	cout << endl;	
	cout << "Deep copy: ";	
	for (i=0; i < 8; i++) {
		narr[i].write(arr[i].read());
		cout << narr[i] << (i < 7 ? ", " : "");
	}
	
	cout << endl;	
}

void intcellarr_shallow() {
	IntCell arr[8];
	IntCell* narr[8];
	int i;
	
	cout << "Original: ";
	for (i=0; i < 8; i++) {
		arr[i].write(i);
		cout << arr[i] << (i < 7 ? ", " : "");
	}

	cout << endl;	
	cout << "Shallow copy: ";	
	for (i=0; i < 8; i++) {
		narr[i] = &arr[i];
		cout << (*narr[i]) << (i < 7 ? ", " : "");
	}
	
	cout << endl;	
}

int main() {
	threenums();
	intcellarr_deep();
	intcellarr_shallow();
	return 0;
}
