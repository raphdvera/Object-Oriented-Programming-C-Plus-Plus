#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

// To Do 1 completed -> adding vector, cstdlib, ctime, and random.

using namespace std;

//------------------------PROTOTYPE-------------------------------------------

// To Do 2 completed -> added correct function prototypes for all functions.
int ranGen(int);
bool readFile(string, vector<string> &);
bool writeFile(string, const vector<string> &, const vector<string> &); // changed prototype for one of To Do #6's part
void promptFile(vector<string> &);
void printVec(vector<string>);
// Completed 2nd To Do by adding function prototypes and setting declarations.

int ranGen(int size){
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> range(0, size - 1);

    return range(generator);
}
// Completed 3rd To Do by hardcoding to 6 -> int ranGen(int size){
// int randomNumber = rand() % size; 
// return randomNumber;

// Completed 4th To Do by changing code above to use <random>.

bool readFile(string filename, vector<string> & vec) { // changed void to bool

   ifstream inputFile(filename);

    //error handling
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file\n";
        return false; // returns false when there's an error
    }

    string line;
    // reads each line and stores it in a vector
    while (getline(inputFile, line)) {
        vec.push_back(line);
    }

    inputFile.close();
    return true; // added true to verify bool once it works
}
// Completed 5th To Do by changing function to bool and returning true and false when necessary.

bool writeFile(string filename, const vector<string> & v0, const vector<string> & v1){ // changed void to bool function and added consts

    ofstream outputFile(filename);
     // error handling
    if (!outputFile) {
        cout << "Error: Could not create data.csv" << filename << endl;
        return false; // when there's an error it will notify us false
    }
    // make sure there are questions before generating a random index
    if (v1.empty())
    {
        cout << "Error: Question bank is empty." << endl;
        return false;
    }

    // write under the structure:
    // Student_Name, Question_#
    for(int i = 0; i < v0.size(); i++){
        outputFile << v0[i] << "," << v1[ranGen(v1.size())] << endl;
    }
    outputFile.close();

    return true; // add true output when function is successful

}
//

int main()
{
    vector<string> roster;
    vector<string> qBank;
    // reading student roster
   if (!readFile("2310_F26_Rosters.csv", roster)){
        return 1;
    }
    // reading question bank
   if (!readFile("Questions.csv", qBank))
   {
    return 1;
   }
    // printVec(roster);
    // printVec(qBank);

    // cout << "Size of roster: " << roster.size() << endl; 
    // cout << "Size of qBank: " << qBank.size() << endl;
    
    // create a CSV output file
    if (!writeFile("Student_question_bank.csv",roster, qBank))
    {
        return 1;
    }

    return 0;
}

//------------------------DECLARATIONS-------------------------------------------
/**
 * @brief prompts the user to give a file to read
 * 
 */
void promptFile(vector<string> & v){
    cout << "file to read?\n";
    string myFile = "";
    cin >> myFile;
    readFile(myFile, v);
}


/**
 * @brief prints out the elements in v
 * 
 * @param v: vector<string>
 */
void printVec(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}