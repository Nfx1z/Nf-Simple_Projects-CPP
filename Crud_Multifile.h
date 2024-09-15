#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>


namespace crud{

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
	int getOption(){

		int input;
		system("cls"); // for cleaning the output window in the windows [system("clear")in mac/std:: ios]
		std:: cout << "CRUD PROGRAM FOR STUDENT DATA" << std:: endl;
		std:: cout << "-----------------------------" << std:: endl;
		std:: cout << "1. Create a new student data| " << std:: endl;
		std:: cout << "2. Display the student data | " << std:: endl;
		std:: cout << "3. Change a student data    | " << std:: endl;
		std:: cout << "4. Delete a student data    | " << std:: endl;
		std:: cout << "5. Finish    		    | " << std:: endl;
		std:: cout << "-----------------------------" << std:: endl;
		std:: cout << "Choose [1 - 5] : ";
		
		std:: cin >> input;
		std:: cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');	// std:: cin.ignore to ignore new line from std:: cin to getline so the getline still working
		return input;
	}

	// this function is for check if the data is exist or not
	void checkDataBase(std:: fstream &data){

		data.open("data.bin", std:: ios:: out | std:: ios:: in | std:: ios:: binary);
		// check the data is exist or not
		if(data.is_open() ){
			std:: cout << "found" << std:: endl;
		}else{
			data.close();
			data.open("data.bin", std:: ios:: trunc | std:: ios:: out | std:: ios:: in | std:: ios:: binary);
		}
	}

	// to tell how much data at the external file
	int dataSize(std:: fstream &data){

		int start, end;
		data.seekg(0, std:: ios:: beg);
		start = data.tellg();	// (data.tellg)it will take the position
		data.seekg(0, std:: ios:: end);
		end = data.tellg();
		return (end-start)/sizeof(Student);
	}

	// to write data at external file with binary
	void writeData(std:: fstream &data, int position, Student &inputData){

		// (std:: ios:: beg)begin, after getting the position it will be forward
		data.seekp( (position - 1)*sizeof(Student), std:: ios:: beg);
		data.write(reinterpret_cast<char*>(&inputData), sizeof(Student) );
	}

	// to read data at external file
	Student readData(std:: fstream &data, int position){

		Student readStudentData;
		// to the first of the data untill the end of the data in the external file
		data.seekg( (position - 1)*sizeof(Student), std:: ios:: beg);
		data.read(reinterpret_cast<char*>(&readStudentData), sizeof(Student) );

		return readStudentData;
	}

	// to add or input a new data to external file
	void addStudentData(std:: fstream &data){

		int size = dataSize(data);
		Student inputData, temporaryData;

		std:: cout << "Data size : " << size << std:: endl << std:: endl;

		std:: cout << "NIM   : ";
		//getline(std:: cin, inputData.NIM); 
		std:: cin.getline(inputData.NIM, 20);
		std:: cout << "Name  : ";
		//getline(std:: cin, inputData.name);
		std:: cin.getline(inputData.name, 50);
		std:: cout << "Major : ";
		//getline(std:: cin, inputData.major);
		std:: cin.getline(inputData.major, 50);
		std:: cout << std:: endl;

		if (size == 0){
			inputData.pk = 1;
		}else{
			temporaryData = readData(data, size);
			inputData.pk = temporaryData.pk + 1;
		}

		writeData(data, size + 1, inputData);
	}

	// to display all available data from external file
	void displayStudentData(std:: fstream &data){

		int size = dataSize(data);

		std:: cout << std:: endl;
		std:: cout << "------------------------------------------------------------";
		std:: cout << "------------------------------------------------------------" << std:: endl;
		std:: cout << "| No\t" << "| PK\t" << "|\tNIM\t\t| " << "\t\tName\t\t\t| " << "\t\tMajor\t\t\t|" << std:: endl; 
		std:: cout << "------------------------------------------------------------";
		std:: cout << "------------------------------------------------------------" << std:: endl;

		for (int number = 1; number <= size; number++){

			Student displayData = readData(data, number);
			std:: cout.fill(' ');

			std:: cout << "| " << std:: setw(6) << std:: left << number; 
			std:: cout << "| " << std:: setw(6) << std:: left << displayData.pk ;
			std:: cout << "| " << std:: setw(22) << std:: left << displayData.NIM ;
			std:: cout << "| " << std:: setw(38) << std:: left << displayData.name ;
			std:: cout << "| " << std:: setw(37) << std:: left << displayData.major << "|" << std:: endl ;
		}
		std:: cout << "============================================================";
		std:: cout << "============================================================" << std:: endl ;
		std:: cout << std:: endl;
	}

	// to change the selected student data
	void changeStudentData(std:: fstream &data){

		int number;
		Student updateData;

		std:: cout << "Choose number on data to be changed : ";
		std:: cin >> number;
		std:: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		updateData = readData(data, number);

		std:: cout << std:: endl;
		std:: cout << "NIM   : ";
		std:: cin.getline(updateData.NIM, 20);
		//getline(std:: cin, updateData.NIM);
		std:: cout << "Name  : ";
		std:: cin.getline(updateData.name, 50);
		//getline(std:: cin, updateData.name);
		std:: cout << "Major : ";
		std:: cin.getline(updateData.major, 50);
		//getline(std:: cin, updateData.major);
		std:: cout << std:: endl;

		writeData(data, number, updateData);

	}

	// to delete a student data and move it to temporary data and sort it after that we move it to data.bin
	void deleteStudentData(std:: fstream &data){

		int number, size, offset;
		Student blankData, tempData;
		std:: fstream tempFile;

		size = dataSize(data);
		std:: cout << "Choose number on data to be deleted : ";
		std:: cin >> number;
		std:: cin.ignore(1, '\n');
		// in other words this code below means change the selected data with empty data (delete)
		blankData = readData(data, number );
		blankData.pk = 0;
		writeData(data, number, blankData);

		tempFile.open("temp.dat", std:: ios:: trunc | std:: ios:: out | std:: ios:: in | std:: ios:: binary);
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
		data.open("data.bin", std:: ios:: trunc | std:: ios:: out | std:: ios:: in | std:: ios:: binary);
		data.close();
		data.open("data.bin", std:: ios:: out | std:: ios:: in | std:: ios:: binary);

		for (int var = 1; var <= size; var++){
			tempData = readData(tempFile, var);
			writeData(data, var, tempData);
		}
	}
}