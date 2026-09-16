#include<iostream>
#include<fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

// To Do 1 completed by adding vector, cstdlib, ctime as well as adding random.

using namespace std;

//---------------------------PROTOTYPES---------------------------

// To Do 2 completed by adding the correct function prototypes for all functions.

int ranGen(int);
bool readFile(string, vector<string> &);
bool writeFile(string, const vector<string> &, const vector<string> &);
void promptFile(vector<string> &);
void printVec(vector<string>);

//---------------------------FUNCTIONS---------------------------

int ranGen(int size)
{
    // To Do 3 completed by using size of question bank instead of 6.
    // To Do 4 completed by using <random>
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> range(0, size - 1);

    return range(generator);
}

bool readFile(string filename, vector<string> & vec)
{
    ifstream inputFile(filename);

    // error handling
    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open file\n";
        return false;
    }

    string line;

    // read each line and stores in vector
    while (getline(inputFile, line))
    {
        vec.push_back(line);
    }

    inputFile.close();

    // To Do 5 completed as function returns true when reading is successful.
    return true;
}
    // To Do 7 completed as v0 and v1 are passed by const reference.
bool writeFile(string filename, const vector<string> & v0, const vector<string> & v1)
{
    // To Do 6 completed as v0 and v1 are passed by const references and it prevents them from being changed.

    ofstream outputFile(filename);

    // error handling
    if(!outputFile)
    {
        cout << "Error: Could not create " << filename << endl;
        return false;
    }

    // to make sure there are questions
    if (v1.empty())
    {
        cout << "Error: Question bank is empty. " << endl;
        return false;
    }

    // write:
    // student_name, random_question
    for (int i = 0; i < v0.size(); i++)
    {
        outputFile << v0[i] << "," << v1[ranGen(v1.size())] << endl;
    }

    outputFile.close();

    return true;
}

//---------------------------MAIN---------------------------

int main()
{
    vector<string> roster;
    vector<string> qBank;

    // reads roster
    if (!readFile("2310_F26_Rosters.csv", roster))
    {
        return 1;
    }

    // reads question bank
    if (!readFile("Questions.csv", qBank))
    {
        return 1;
    }

    // printVec(roster);
    // printVec(qBank);

    // cout << "Size of roster: " << roster.size() << endl;
    // cout << "Size of qBank: " << qBank.size() << endl;

    // create final csv output file
    if (!writeFile("Student_question_bank.csv", roster, qBank))
    {
        return 1;
    }

    return 0;
}

//---------------------------DECLARATIONS---------------------------

// prompts to enter the name of file to read
void promptFile(vector<string> & v)
{
    cout << "File to read?\n";

    string myFile = "";
    cin >> myFile;

    readFile(myFile, v);
}

void printvec(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
