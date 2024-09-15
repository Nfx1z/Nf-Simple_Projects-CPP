#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

struct Student{

// i suggest to using char array because if we using getline here, the input max only 15 letters
// and using string to getline with this code won't work so i suggest just use char array
	int pk;	// primary key usually as a identifier
	char name [50];
	char major [50];
	char NIM [20];
	// string name;
	// string major;
	// string NIM;
};

// this function is for the menu
int getOption();

// this function is for check if the data is exist or not
void checkDataBase(fstream &data);

// to tell how much data at the external file
int dataSize(fstream &data);

// to write data at external file with binary
void writeData(fstream &data, int position, Student &inputData);

// to read data at external file
Student readData(fstream &data, int position);

// to add or input a new data to external file
void addStudentData(fstream &data);

// to display all available data from external file
void displayStudentData(fstream &data);

// to change the selected student data
void changeStudentData(fstream &data);

// to delete a student data and move it to temporary data and sort it after that we move it to data.bin
void deleteStudentData(fstream &data);


int main(){

	fstream data;
	checkDataBase(data);
	
	int option = getOption();
	string if_continue;

	enum enumOption{ CreateData = 1, DisplayData, ChangeData, DeleteData, Finish};
	while(option >= CreateData and option < Finish){
		switch(option){
			case CreateData:
				cout << "=============================" << endl;
				cout << "1. Create a new student data" << endl;
				cout << "=============================" << endl;
				addStudentData(data);
				break;
			case DisplayData:
				cout << "=============================" << endl;
				cout << "2. Display the student data  " << endl;
				cout << "=============================" << endl;
				displayStudentData(data);
				break;
			case ChangeData:
				cout << "=============================" << endl;
				cout << "3. Change a student data     " << endl;
				cout << "=============================" << endl;
				displayStudentData(data);
				changeStudentData(data);
				break;
			case DeleteData:
				cout << "=============================" << endl;
				cout << "4. Delete a student data     " << endl;
				cout << "=============================" << endl;
				displayStudentData(data);
				deleteStudentData(data);
				break;
			default:
				cout << "Unknown option " << endl << endl;
		}
		continue_Program:			// from this, the program will rerun continiously if the code point to this 

		cout << "Cotinue the program? (y/n) : ";
		cin >> if_continue;
		if ( if_continue == "y" or if_continue == "Y" or if_continue == "yes" or if_continue == "YES"){
			option = getOption();	// to change the option so the case is changing too, if doesn't the option will stuck at certain case
		}else if( if_continue == "n" or if_continue == "N" or if_continue == "no" or if_continue == "NO"){
			break;
		}else{
			goto continue_Program;	// to rerun the program from a specific line 
		}
	}

	data.close();
	system("cls");
	cout << "The Program has been closed" << endl;
	
	cin.get();
	return 0;
}

// this function is for the menu
int getOption(){

	int input;
	system("cls"); // for cleaning the output window in the windows [system("clear")in mac/ios]
	cout << "CRUD PROGRAM FOR STUDENT DATA" << endl;
	cout << "-----------------------------" << endl;
	cout << "1. Create a new student data| " << endl;
	cout << "2. Display the student data | " << endl;
	cout << "3. Change a student data    | " << endl;
	cout << "4. Delete a student data    | " << endl;
	cout << "5. Finish    		    | " << endl;
	cout << "-----------------------------" << endl;
	cout << "Choose [1 - 5] : ";
	
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');	// cin.ignore to ignore new line from cin to getline so the getline still working
	return input;
}

// this function is for check if the data is exist or not
void checkDataBase(fstream &data){

	data.open("data.bin", ios :: out | ios :: in | ios :: binary);
	// check the data is exist or not
	if(data.is_open() ){
		cout << "found" << endl;
	}else{
		data.close();
		data.open("data.bin", ios :: trunc | ios :: out | ios :: in | ios :: binary);
	}
}

// to tell how much data at the external file
int dataSize(fstream &data){

	int start, end;
	data.seekg(0, ios :: beg);
	start = data.tellg();	// (data.tellg)it will take the position
	data.seekg(0, ios :: end);
	end = data.tellg();
	return (end-start)/sizeof(Student);
}

// to write data at external file with binary
void writeData(fstream &data, int position, Student &inputData){

	// (ios::beg)begin, after getting the position it will be forward
	data.seekp( (position - 1)*sizeof(Student), ios :: beg);
	data.write(reinterpret_cast<char*>(&inputData), sizeof(Student) );
}

// to read data at external file
Student readData(fstream &data, int position){

	Student readStudentData;
	// to the first of the data untill the end of the data in the external file
	data.seekg( (position - 1)*sizeof(Student), ios :: beg);
	data.read(reinterpret_cast<char*>(&readStudentData), sizeof(Student) );

	return readStudentData;
}

// to add or input a new data to external file
void addStudentData(fstream &data){

	int size = dataSize(data);
	Student inputData, temporaryData;

	cout << "Data size : " << size << endl << endl;

	cout << "NIM   : ";
	//getline(cin, inputData.NIM); 
	cin.getline(inputData.NIM, 20);
	cout << "Name  : ";
	//getline(cin, inputData.name);
	cin.getline(inputData.name, 50);
	cout << "Major : ";
	//getline(cin, inputData.major);
	cin.getline(inputData.major, 50);
	cout << endl;

	if (size == 0){
		inputData.pk = 1;
	}else{
		temporaryData = readData(data, size);
		inputData.pk = temporaryData.pk + 1;
	}

	writeData(data, size + 1, inputData);
}

// to display all available data from external file
void displayStudentData(fstream &data){

	int size = dataSize(data);

	cout << endl;
	cout << "------------------------------------------------------------";
	cout << "------------------------------------------------------------" << endl;
	cout << "| No\t" << "| PK\t" << "|\tNIM\t\t| " << "\t\tName\t\t\t| " << "\t\tMajor\t\t\t|" << endl; 
	cout << "------------------------------------------------------------";
	cout << "------------------------------------------------------------" << endl;

	for (int number = 1; number <= size; number++){

		Student displayData = readData(data, number);
		cout.fill(' ');

		cout << "| " << setw(6) << left << number; 
		cout << "| " << setw(6) << left << displayData.pk ;
		cout << "| " << setw(22) << left << displayData.NIM ;
		cout << "| " << setw(38) << left << displayData.name ;
		cout << "| " << setw(37) << left << displayData.major << "|" << endl ;
	}
	cout << "============================================================";
	cout << "============================================================" << endl ;
	cout << endl;
}

// to change the selected student data
void changeStudentData(fstream &data){

	int number;
	Student updateData;

	cout << "Choose number on data to be changed : ";
	cin >> number;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	updateData = readData(data, number);

	cout << endl;
	cout << "NIM   : ";
	cin.getline(updateData.NIM, 20);
	//getline(cin, updateData.NIM);
	cout << "Name  : ";
	cin.getline(updateData.name, 50);
	//getline(cin, updateData.name);
	cout << "Major : ";
	cin.getline(updateData.major, 50);
	//getline(cin, updateData.major);
	cout << endl;

	writeData(data, number, updateData);

}

// to delete a student data and move it to temporary data and sort it after that we move it to data.bin
void deleteStudentData(fstream &data){

	int number, size, offset;
	Student blankData, tempData;
	fstream tempFile;

	size = dataSize(data);
	cout << "Choose number on data to be deleted : ";
	cin >> number;

	// in other words this code below means change the selected data with empty data (delete)
	blankData = readData(data, number );
	blankData.pk = 0;
	writeData(data, number, blankData);

	tempFile.open("temp.dat", ios :: trunc | ios :: out | ios :: in | ios :: binary);
	offset = 0;

	for (int var = 1; var <= size; var++){
		tempData = readData(data, var);
		if (not tempData.pk == 0){
			writeData(tempFile, (var - offset), tempData);
		}else{
			offset++;
		}
	}
	// we move the data to temporary File
	// the code below to empty data.bin
	size = dataSize(tempFile);
	data.close();
	data.open("data.bin", ios :: trunc | ios :: out | ios :: in | ios :: binary);
	data.close();
	data.open("data.bin", ios :: out | ios :: in | ios :: binary);

	for (int var = 1; var <= size; var++){
		tempData = readData(tempFile, var);
		writeData(data, var, tempData);
	}
}

