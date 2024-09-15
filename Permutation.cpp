/*
                                THIS CODE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
                                BY : VKEY
*/

// =========================================== PURPOSE OF THIS PROGRAM =================================================
/*
Permutation Logic
1234    2134    3214    4231
1243    2143    3241    4213

1324    2314    3124    4321
1342    2341    3142    4312

1432    2431    3421    4132
1423    2413    3412    4123
*/
// ================================================== LIBRARY ==========================================================
#include <iostream> // std::cout, std::endl
#include <string> // erase(), size()
#include <algorithm> // std::remove()
// ================================================= FUNCTIONS =========================================================
// For 5 words, there is 4 loop for()
// If 4 words, then there is 3 loop for()
/* For n words, there is n-1 loop for() we used
void permutationManual(std::string& str, int& size){ // This for 5 words
    for(int i = 0; i < size; i++){
        std::swap(str[0], str[i]);
        for(int j = 1; j < size; j++){
            std::swap(str[1], str[j]);
            for(int k = 2; k < size; k++){
                std::swap(str[2], str[k]);
                for(int l = 3; l < size; l++){
                    std::swap(str[3], str[l]);
                    std::cout << str << std::endl;
                    std::swap(str[3], str[l]);
                }
                std::swap(str[2], str[k]);
            }
            std::swap(str[1], str[j]);
        }
        std::swap(str[0], str[i]);
    }
}*/

// This function is similar to the function permutationManual()
// The difference is this function use recursion function
// So it's automatically generated the loop for() and it depends on the size of the string
void permutation(std::string& str,int args, int& size){
    if(args == size){
        std::cout << str << "\t";
    }else{
        // Permutations made
        for(int index = args; index < size; index++){
            // Swapping
            std::swap(str[args], str[index]);
            // Recursion called
            permutation(str, (args + 1), size);
            // Backtracking or to make it to the first value again
            std::swap(str[args], str[index]);
        }
    }
}
// =============================================== MAIN PROGRAM ========================================================
int main(){
    //system("clear");
    // string to store input and temporary
    std::string inputStr, tempStr;
    std::cout << "INPUT ARGUMENTS : ", std::cin >> inputStr;
    std::cout << std::endl;
    // to remove spaces from the string
    inputStr.erase( std::remove(inputStr.begin(), inputStr.end(), ' '), inputStr.end());
    int strSize = inputStr.size();
    //permutationManual(str, size); // If want use this function make sure you input 5 words or it won't work properly
    permutation(inputStr, 0, strSize);
    return 0;
}
