//Objective:  input scores between 0 -100 until sentinel value of -1, and output number of scores and average score
//Name: Teacher
//Course: COMSC-110-1021
//Compiler: MinGW
//Editor: MS NotePad

#include <iostream> 
using namespace std;
#include <fstream>


struct Score
{
    int value;  
    Score* next; 
};


void introduction(string obj);

int main()
{
    //data
    int count = 0; 
    int sum = 0; 
    float average;
    Score* p;
    int max = INT_MIN;
    int min = INT_MAX;
    Score* start = 0;  
    Score* aScore; 
    Score* nextNode; 
    string objective = "read scores from input file (scores.txt) and calculate the average, highest, lowest scores and number of scores greater than the average, using a linked list\n";
    int high = 0;
    int temp;
    introduction(objective);   

        ifstream fin;
        string filename = "scores.txt";
        fin.open(filename.c_str());
        if (!fin.good()) throw "I/O error";
        while (fin.good()) {
        aScore = new Score;
        fin >> aScore->value;
        fin.ignore(1000, 10);
            
        if (aScore->value == -1) break;     
        if (aScore->value >= 0 && aScore->value <= 100)
        {
            aScore->next = start;
            start = aScore;
        }
        
        }
        fin.close();

    for (p = start; p; p = p->next)
    {
        sum += p->value;
        count++;
    }
    if (count > 0)
    {
        average = (float)sum / count;
        cout << "Average of " << count << " scores: " << average << endl;
    }
    else
        cout << "No values were entered.\n";

    for (p = start; p; p = p->next) {

        if (p->value > average) {
            high++;
        }
    }

    while (start != NULL) {
        if (min > start->value) {
            min = start->value;
        }
        if (max < start->value) {
            max = start->value;
        }
        start = start->next;
    }
    start = 0;
    cout << "Scores greater than the average: " << high << endl;
    cout << "Lowest Score: " << min<< endl; 
    cout << "Highest Score: " << max << endl;


    while (start)
    {
        nextNode = start->next;
        delete start;
        start = nextNode;
    } 
}
void introduction(string obj)
{
    cout << "Objective: This program will ";
    cout << obj << ".\n";
    cout << "Programmer: Robert Cacho\n";
    cout << "Editor(s) used: Notepad\n";
    cout << "Compiler(s) used: MinGW\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
}
