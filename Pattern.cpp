#include <iostream>
using namespace std;

void pattern1(int &input){
	cout << " Pattern 1 \n\n";
	for (int var1 = 1; var1 <= input; var1++){
		for (int var2 = 1; var2 <= var1; var2++){
			cout << "*" ;
		}
		cout << endl;
	}
}

void pattern2(int &input){
	cout << "\n Pattern 2 \n\n";
	for (int var1 = 1; var1 <= input; var1++){
		for (int var2 = input; var2 >= var1; var2--){
			cout << "*";
		}
		cout << endl;
	}
}

void pattern3(int &input){
	cout << "\n Pattern 3 \n\n";
	for (int var1 = 1; var1 <= input; var1++){
		for (int var2 = input; var2 >= var1; var2--){
			cout << " ";
		}
		for (int var3 = 1; var3 <= var1; var3++){
			cout << "*";
		}
		cout << endl;
	}
}

void pattern4(int &input){
	cout << "\n Pattern 4 \n\n";
	for (int var1 = 1; var1 <= input; var1++){
		for (int var2 = 1; var2 <= var1; var2++){
			cout << " " ;
		}
		for (int var3 = input; var3 >= var1; var3--){
			cout << "*" ;
		}
		cout << endl;
	}

}

void pattern5(int &input){
	cout << "\n Pattern 5 \n\n";
	for (int var1 = 1; var1 <= input; var1++){
		for (int var2 = input; var2 >= var1; var2--){
			cout << " ";
		}
		for (int var3 = 1; var3 <= var1; var3++){
			cout << "*";
		}
		for (int var4 = 2; var4 <= var1; var4++){
			cout << "*";
		}
		cout << endl;
	}
}

void pattern6(int &input){
	cout << "\n Pattern 6 \n\n";
	for (int var1 = 1; var1 <= input; var1++){
		for (int var2 = 1; var2 <= var1; var2++){
			cout << " ";
		}
		for (int var3 = input; var3 >= var1; var3--){
			cout << "*";
		}
		for (int var4 = input; var4 > var1; var4--){
			cout << "*";
		}
		cout << endl;
	}
}

void pattern7(int &input){
	cout << "\n Pattern 7 \n\n";
		for (int var1 = 1; var1 <= input; var1++){
			for (int var2 = input; var2 >= var1; var2--){
			cout << " ";
			}
			for (int var3 = 1; var3 <= var1; var3++){
			cout << "*";
			}
			for (int var4 = 2; var4 <= var1; var4++){
			cout << "*";
			}
		cout << endl;
		}
		for (int var1 = 1; var1 <= input; var1++){
			for (int var2 = 0; var2 <= var1; var2++){
			cout << " ";
			}
			for (int var3 = (input-1); var3 >= var1; var3--){
			cout << "*";
			}
			for (int var4 = (input-1); var4 > var1; var4--){
			cout << "*";
			}
		cout << endl;
		}
}

void pattern8(int &input){
	cout << "\n Pattern 8 \n\n";
		for (int var1 = 1; var1 <= input; var1++){
			for (int var2 = input; var2 >= var1; var2--){
				cout << "*";
			}
			for (int var3 = 1; var3 <= var1; var3++){
				cout << " ";
			}
			for (int var4 = 2; var4 <= var1; var4++){
				cout << " ";
			}
			for (int var5 = input; var5 >= var1; var5--){
				cout << "*";
			}
			cout << endl;
		}
		for (int var1 = 1; var1 <= input; var1++){
			for (int var2 = 1; var2 <= var1; var2++){
				cout << "*";
			}
			for (int var3 = input; var3 >= var1; var3--){
				cout << " ";
			}
			for (int var4 = input-1; var4 >= var1; var4--){
				cout << " ";
			}
			for (int var5 = 1; var5 <= var1; var5++){
				cout << "*";
			}
			cout << endl;
		}

}

int main (){
	
	int input, type_input; // input is the pattern length
	cout << "Input type of pattern : "; std::cin >> type_input;
	cout << "Insert pattern length : "; cin >> input;

		pattern1(input);
		pattern2(input);
		pattern3(input);
		pattern4(input);
		pattern5(input);
		pattern6(input);
		pattern7(input);
		pattern8(input);

	
	cin.get();
	return 0;
}
