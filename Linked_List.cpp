/*
                                THIS CODE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
                                BY : VKEY
*/

// =========================================== PURPOSE OF THIS PROGRAM =================================================
/*
            SINGLE LINKED LIST WITH STRUCT
THAT CAN INPUT at the FIRST, at the MIDDLE, or at the END 
AND CAN REMOVE at the FIRST, at the MIDDLE, or at the END

    data1 -> null // single linked list
    data2 -> data1 -> null // input/add at the first(head)
    data1 -> data2 -> null // input/add at the end(tail)
    data1 -> data3 -> data2 -> null // input/add the middle
*/
// ================================================== LIBRARY ==========================================================
#include <iostream> // std::cout, std::cin, std::endl
#include <string> // std::string,
#include <iomanip> // std::setprecision(), std::setw(), std::left, std::right
using namespace std;
// ============================================== GLOBAL VARIABLES =====================================================
// linked list with struct
struct student{
    string NIM;
    string Name;
    int Year;
    string Major;

    student* next;
};
// global variables for linked list
student *head, *tail, *middle, *current, *newNode, *deleteNode;
// global variables for input
string NIM, Name, Major;
int Year;

// ================================================ PROTOTYPES =========================================================

int getLength();
void first(string, string, int, string);
void addHead(string, string, int, string);
void removeHead();
void addTail(string, string, int, string);
void removeTail();
void addMiddle(string, string, int, string);
void printList();
void menuDisplay();

// =============================================== MAIN PROGRAM ========================================================
int main(){
    // display the menu
    system("cls"); // clear the terminal // in linux use ("clear")
    menuDisplay();
    // delete the usage memory
    delete head;
    delete tail;
    delete middle;
    delete current;
    delete newNode;
    return 0;

}
// ================================================= FUNCTIONS =========================================================

// funciton to get the length of the linked list
int getLength(){
    int length = 0;
    current = head;
    while(current != NULL){
        length++;
        current = current -> next;
    }
    return length;
}

// function to make a single linked list
void first(string sNIM, string sName, int iYear, string sMajor){
    head = new student;
    head -> NIM = sNIM;
    head -> Name = sName;
    head -> Year = iYear;
    head -> Major = sMajor;
    head -> next = NULL; // head next point to NULL
    tail = head; // the first data equal to the last data
}

// function to add a new data at the first of linked list
void addHead(string sNIM, string sName, int iYear, string sMajor){
    newNode = new student;
    newNode -> NIM = sNIM;
    newNode -> Name = sName;
    newNode -> Year = iYear;
    newNode -> Major = sMajor;
    newNode -> next = head; // the new data point next to current head before we change head with the new data
    head = newNode; // the new data become the head linked list
}

// function to remove the head of linked list
void removeHead(){
    deleteNode = head;
    head = head -> next;
    delete deleteNode;
}

// function to add a new data at the last of linked list
void addTail(string sNIM, string sName, int iYear, string sMajor){
    newNode = new student;
    newNode -> NIM = sNIM;
    newNode -> Name = sName;
    newNode -> Year = iYear;
    newNode -> Major = sMajor;
    newNode -> next = NULL; // the new data point next to NULL so it will be the tail
    tail -> next = newNode; // the current tail point next to new data before we change the tail with new data
    tail = newNode; // the new data become the tail of linked list
}

// function to remove tail of linked list
void removeTail(){
    current = head;
    // if data only one
    if(current -> next == NULL){
        deleteNode = head;
        head = current -> next;
    }else{
        deleteNode = tail;
        while(current -> next != tail)
            current = current -> next;
        tail = current;
        tail -> next = NULL;
    }
    delete deleteNode;
}

// function to add in the middle of linked list
void addMiddle(string sNIM, string sName, int iYear, string sMajor){
    // to get the middle of the linked list
    int length = getLength();
    if(length % 2 == 1) // if length is ODD number
        length = length/2 + 1;
    else // if length is EVEN number
        length = length/2;
    
    // to start from head
    int tempLength = 1;
    current = head;
    while(true){
        // if already at the middle of the list
        if(tempLength == length){
            middle = new student;
            middle -> NIM = sNIM;
            middle -> Name = sName;
            middle -> Year = iYear;
            middle -> Major = sMajor;
            middle -> next = current -> next; // point the middle next to current next
            current -> next = middle; // point current next to the middle
            break;
        }
        // if not, run untill reach the middle of the list
        else    current = current -> next;
        tempLength++;
    }
}

// function to remove in the middle of the list
void removeMiddle(){
    // to get the middle of the linked list
    int length = getLength();
    if(length % 2 == 1) // if length is ODD number
        length = length/2 + 1;
    else // if length is EVEN number
        length = length/2;

    // index length of the current list
    int tempLength = 1;
    // start from the head of the list
    current = head;
    // for declare that the middle of the list is the one that will be delete
    while(true){
        // if already in the middle of the list
        if(tempLength == length ){
            // deleteNode equal to the middle of the list
            deleteNode = current; 
            break;
        }
        // if not, run untill reach the middle of the list
        else    current = current -> next;
        tempLength++;
    }
    // index length of the current list
    tempLength = 1;
    // start from the head of the list
    current = head;
    // for delete the deleteNode 
    while(true){
        // if already in one before the middle of the list
        if(tempLength == (length-1)){
            // point the current next to deleteNode(middle of the list) next
            current -> next = deleteNode -> next;
            // delete the middle of the list
            delete deleteNode;
            break;
        }
        // if not, run untill reach the middle of the list
        else   current = current -> next;
        tempLength++;
    }
    
}

// function to display or print the list
void printList(){
    current = head; // current now become the head for display
    cout.fill(' '); // fill with ' '
    // display head of menu
    cout << "\n----------------------------------------------------------------------------\n";
    cout << "| " << setw(7) << right << "NIM"  << setw(6) << "|" << setw(15) << "NAME" << setw(13);
    cout << "|" << setw(5) << "YEAR" << setw(2) << "|" << setw(16) << "MAJOR" << setw(10) << "|";
    cout << "\n----------------------------------------------------------------------------\n";
    if(current != NULL){
        while(current != NULL){
            // display student NIM and set the space also the text to left side
            cout << "| " << setw(12) << left << current -> NIM;
            // display student Name and set the space also the text to left side
            cout << "| " << setw(26) << left << current -> Name;
            // display student Year and set the space also the text to left side
            cout << "| " << setw(5) << left << current -> Year;
            // display student Major and set the space also the text to left side
            cout << "| " << setw(24) << left << current -> Major << "|\n";
            // point to the next node untill NULL or tail
            current = current->next;
        }
    }else
        cout << "\t\t\t\tEMPTY LIST\n";
    cout << "----------------------------------------------------------------------------\n";
}

// function to display the menu
void menuDisplay(){
    int length; // to store length of the list
    int option; // to store the menu option 
    char choice; // to store continue the program or not
    while(true){
        length = getLength(); // length of the list
        cout << "\n\n\t\tMAIN MENU\n";
        cout << "----------------------------------------\n";
        cout << " 1. Add the FIRST DATA\n";
        cout << " 2. Add DATA HEAD\n";
        cout << " 3. Add DATA TAIL\n";
        cout << " 4. Add the MIDDLE DATA\n";
        cout << " 5. Remove DATA HEAD\n";
        cout << " 6. Remove DATA TAIL\n";
        cout << " 7. Remove the MIDDLE DATA\n";
        cout << " 8. Display List\n";
        cout << "----------------------------------------\n";

        cout << "Option >> "; cin >> option;
        // first data in the list
        if(option == 1){
            // for first data only
            if(length == 0){
                system("cls"); // clear the terminal // in linux use ("clear")
                cout << "\n\t\t\t======== Input FIRST DATA ========\n";
                cout << "NIM : "; cin >> NIM; cin.ignore(1,'\n'); // ignore auto new line std::cin
                cout << "NAME : "; getline(cin, Name);
                cout << "YEAR : "; cin >> Year; cin.ignore(1,'\n'); // ignore auto new line std::cin
                cout << "MAJOR : "; getline(cin, Major);
                first(NIM, Name, Year, Major);
                printList();    
            }else{
                system("cls");  // clear the terminal // in linux use ("clear")
                cout << "\n\n\t\tDATA ALREADY IN THE LIST\n";
                continue;
            }
        }
        // add data head in the list
        else if(option == 2){
            if(length != 0){
                system("cls"); // clear the terminal // in linux use ("clear")
                cout << "\n\t\t\t======== Input DATA HEAD ========\n";
                cout << "NIM : "; cin >> NIM; cin.ignore(1,'\n'); // ignore auto new line std::cin
                cout << "NAME : "; getline(cin, Name);
                cout << "YEAR : "; cin >> Year; cin.ignore(1,'\n'); // ignore auto new line std::cin
                cout << "MAJOR : "; getline(cin, Major);
                addHead(NIM, Name, Year, Major);
                printList();
            }else{
                cout << "\n\t\tThe List is Empty\n\n";
                continue;
            }
            
        }
        // add data tail in the list
        else if(option == 3){
            if(length != 0){
                system("cls"); // clear the terminal // in linux use ("clear")
                cout << "\n\t\t\t======== Input DATA TAIL ========\n";
                cout << "NIM : "; cin >> NIM; cin.ignore(1,'\n'); // ignore auto new line std::cin
                cout << "NAME : "; getline(cin, Name);
                cout << "YEAR : "; cin >> Year; cin.ignore(1,'\n'); // ignore auto new line std::cin
                cout << "MAJOR : "; getline(cin, Major);
                addTail(NIM, Name, Year, Major);
                printList();
            }else{
                cout << "\n\t\tThe List is Empty\n\n";
                continue;
            }
        }
        // add data in the middle of the list
        else if(option == 4){
            if(length != 0){
                system("cls"); // clear the terminal // in linux use ("clear")
                cout << "\n\t\t\t======== Input in the MIDDLE DATA =======\n";
                cout << "NIM : "; cin >> NIM; cin.ignore(1,'\n'); // ignore auto new line std::cin
                cout << "NAME : "; getline(cin, Name);
                cout << "YEAR : "; cin >> Year; cin.ignore(1,'\n'); // ignore auto new line std::cin
                cout << "MAJOR : "; getline(cin, Major);
                addMiddle(NIM, Name, Year, Major);
                printList();
            }else{
                cout << "\n\t\tThe List is Empty\n\n";
                continue;
            }
        }
        // remove data head in the list
        else if(option == 5){
            if(length != 0){
                system("cls"); // clear the terminal // in linux use ("clear")
                cout << "\n\t\t\t======== Remove DATA HEAD =======\n";
                removeHead();
                printList();
            }else{
                cout << "\n\t\tThe List is Empty\n\n";
                continue;
            }
        }
        // remove data tail in the list
        else if(option == 6){
            if(length != 0){
                system("cls"); // clear the terminal // in linux use ("clear")
                cout << "\n\t\t\t======== Remove DATA TAIL =======\n";
                removeTail();
                printList();
            }else{
                cout << "\n\t\tThe List is Empty\n\n";
                continue;
            }
        }
        // remove data in the middle of the list
        else if(option == 7){
            if(length > 2){
                system("cls"); // clear the terminal // in linux use ("clear")
                cout << "\n\t\t\t======== Remove MIDDLE DATA =======\n";
                removeMiddle();
                printList();
            }else{
                cout << "\n\t\tMiddle data wasn't found\n\n";
                continue;
            }
        }
        // display or print the current list
        else if(option == 8){
            system("cls"); // clear the terminal // in linux use ("clear")
            cout << "\n\t\t\t======== DISPLAY the LIST =======\n\n";
            printList();
        }
        else{
            system("cls");
            cout << "\n----------------------------------------\n";
            cout << " UNKNOWN OPTION!!, Please Selecet (1-8)";
            cout << "\n----------------------------------------\n";
            continue;
        }

        // continue program or not
        cout << "\nContinue program ? (Y/N)"; cin >> choice;
        choice = toupper(choice); // to upper the input
        if(choice == 'N'){
            cout << "\n\t\t\t======== Stop the PROGRAM ========\n\n";
            break; // stop the loop
        }else if(choice == 'Y')      
            continue; // continue the loop
        else{
            cout << "\n\t\t\tUNKNOWN CHOICE !!\n\n";
            break;
        }
    }
}
