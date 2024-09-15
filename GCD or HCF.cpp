#include <iostream>

// GCD (Greatest Common Divisor) or HCF(Highest Common Factor) is the largest number that divides both of them
// 36 = 2 x 2 x 3 x 3
// 60 = 2 x 2 x 3 x 5
// GCF or HCF = 2 x 2 x 3 = 12
// we intialize num_one = A, num_two = B
// both of the code below output the same result but different way 
int GCDmodulo(int num_one, int num_two){

// this code use modulo, and the process is if std:: cout << GCD(40,56) << std:: endl;
// (56, 40 % 56) => (40, 56 % 40) => (16, 40 % 16) => (8, 16 % 8) => (8, 0) => the output : 8
	if(num_two == 0){
		return num_one;
	}
	return GCDmodulo(num_two, num_one%num_two);
}

int HCFcommon( int num_one, int num_two){
// this code use normal operation and using command 'if' and the process is if std:: cout << GCD (36,24) or GCD(40, 56)
// (36 - 24, 24) => (12, 24 - 12) => (12, 12) => the output : 12
// (40, 56 - 40) => (40 - 16, 16) => (24 - 16, 16) => (8, 16 - 8) => (8, 8) => the output : 8
	if(num_one == 0){
		return num_two;
	}
	if(num_two == 0){
		return num_one;
	}
	if(num_one == num_two){
		return num_one;
	}
	if(num_one > num_two){
		return HCFcommon(num_one - num_two, num_two);
	}
	return HCFcommon(num_one, num_two - num_one);

}
// why we don't use reference or pointer ? Because in recursive function if we use one of them the code won't work 
// because inside the function, it calls the function itself

int main(){
	int num_one, num_two;
	std:: cin >> num_one >> num_two;
	std:: cout << "Result with modulo operator : " << GCDmodulo(num_one, num_two) << std:: endl;
	std:: cout << "Result with common operator : " << HCFcommon(num_one, num_two) << std:: endl;
	std:: cin.get();
	return 0;
}