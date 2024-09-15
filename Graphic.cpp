#include <iostream>
#include <array>

using namespace std;

int main(){
	array <int, 20> mark;
	cout << "Total student scores " << endl;
	for (int var = 0; var <= mark.size(); var++){
		if (var == 0 ){
			cout << "Mark 0-4   :" ;
		}else if (var == mark.size()){
			cout << "Mark 100   :";
		}else if(var == 1){
			cout << "Mark 5-9   :" ;
		}else{
			cout << "Mark " << var*5 << "-" << (var*5)+4 << " :";
		}
		cin >> mark[var];	
	}
	cout << endl << endl;
	for (int var = 0; var <= mark.size(); var++){
		if (var == 0 ){
			cout << "Mark 0-4   :";
		}else if (var == mark.size()){
			cout << "Mark 100   :";
		}else if(var == 1){
			cout << "Mark 5-9   :" ;
		}else{
			cout << "Mark " << var*5 << "-" << (var*5)+4 << " :";
		}
		for (int var1 = 1; var1 <= mark[var]; var1++){
			cout << "|" ;
		}
		cout << " value: " << mark[var] ;
		cout << endl;
	}
	cin.get();
	return 0;
}
