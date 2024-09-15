#include <iostream>
#include <string>
#include <fstream>
#include "Crud_Multifile.h"

int main(){
	std:: fstream data;
	crud:: checkDataBase(data);
	
	int option = crud:: getOption();
	std:: string if_continue;

	enum enumOption{ CreateData = 1, DisplayData, ChangeData, DeleteData, Finish};
	while(option >= CreateData and option < Finish){
        system("cls");
		switch(option){
			case CreateData:
				std:: cout << "=============================" << std:: endl;
				std:: cout << "1. Create a new student data" << std:: endl;
				std:: cout << "=============================" << std:: endl;
				crud:: addStudentData(data);
				break;
			case DisplayData:
				std:: cout << "=============================" << std:: endl;
				std:: cout << "2. Display the student data  " << std:: endl;
				std:: cout << "=============================" << std:: endl;
				crud:: displayStudentData(data);
				break;
			case ChangeData:
				std:: cout << "=============================" << std:: endl;
				std:: cout << "3. Change a student data     " << std:: endl;
				std:: cout << "=============================" << std:: endl;
				crud:: displayStudentData(data);
				crud:: changeStudentData(data);
				break;
			case DeleteData:
				std:: cout << "=============================" << std:: endl;
				std:: cout << "4. Delete a student data     " << std:: endl;
				std:: cout << "=============================" << std:: endl;
				crud:: displayStudentData(data);
				crud:: deleteStudentData(data);
				break;
			default:
				std:: cout << "Unknown option " << std:: endl << std:: endl;
		}
		continue_Program:			// from this, the program will rerun continiously if the condition met

		std:: cout << "Cotinue the program? (y/n) : ";
		std:: cin >> if_continue;
		if ( if_continue == "y" or if_continue == "Y" or if_continue == "yes" or if_continue == "YES"){
			option = crud:: getOption();	// to change the option so the case is changing too, if doesn't the option will stuck at certain case
		}else if( if_continue == "n" or if_continue == "N" or if_continue == "no" or if_continue == "NO"){
			break;
		}else{
			goto continue_Program;	// to rerun the program from a specific line 
		}
	}

	data.close();
	system("cls");
	std:: cout << "The Program has been closed" << std:: endl;
	
	std:: cin.get();
	return 0;
}




