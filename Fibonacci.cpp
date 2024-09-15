#include <iostream>

using namespace std;

int main(){
	
	int input, value1 = 1, value2 = 0, result;
	// value1 is (input - 1) and value2 is (input - 2)
	cout << " Fibonacci Sequencce " << " \n please input the number : ";
	cin >> input; // input is the number sequencce
	for (int var = 0; var < input; input-- ){
		result = value1 + value2;
		cout << value1 << "  ";
		value2 = value1;
		value1 = result;
	
	}
	cout << endl << endl;
	
	cin.get();
	return 0;
}
