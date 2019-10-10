#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <time.h>      // time

using namespace std;

// feel free to use this function if you wish
// purpose: generate random coordinates
// input: none
// output: a vector with 2 coordinates between 1,1 and 4,4
vector<int> Get_A_Random_Square() {
    return vector<int>{rand()%4+1, rand()%4+1};
}

// feel free to use this function if you wish
// purpose: verifies if the coordinates of a square fall within the cave
// input: coordinates of a square
// output: true if the square is in the cave otherwise false
bool Is_Square_Valid(const vector<int> &square) {
    for (auto e : square)
        if (e < 1 || e > 4)
            return false;
    return true;
}

// don't change this function
// purpose: prints a map of the cave to the console
// input: the printable map a vector of strings
// output: none - console output of the cave diagram
void Print_Cave_Diagram(const vector<string> &cave_diagram){
    for (auto s : cave_diagram)
        cout<<s<<endl;
}

// Implement these functions below
// Do not change the function prototpyes
void Initialize_Cave(map<vector<int>, set<string> > &cave);
void Print_Square(map<vector<int>, set<string> > &cave, const vector<int> &rc);
void Get_Cave_Diagram(map<vector<int>, set<string> > &cave, vector<string> &cave_diagram);

// sample main function
int main() {
    srand(time(NULL)); // seed the random generator
    
    // Declare the cave data structure to 'map' coordinates to a 'set' of strings describing the cell contents
    map<vector<int>, set<string> > cave;
    
    // Check this out! The cave data structure has a lot going on
    // Uncomment the block below to see a demo of how to use the cave map
    // use the [] to access the set contained in the map
    // insert puts the word "ladder" into the set
    // cave[rc] is the set of words at coordinates rc
    // cave[rc].begin() returns an iterator to the first element of the set
    // note your program will likely crash if the set is empty
    // I recommend checking for this.
    // use the * to dereference the pointer to get the first word stored in the set

     vector<int> rc{1, 1}; // row column
     cave[rc].insert("ladder456");
     cave[rc].insert("ladder123");
     if (cave[rc].empty() != false)
     cout<<"cave square (1,1) contains a "<<*cave[rc].begin()<<endl;

//    cout<<*cave[rc].end()<<endl;
    
    vector<int> abc{1,1};
    cave[abc].insert("abc");
    
    
    int a = 10;
    cout<<&a<<endl<<endl;
    auto b = &a;
    cout<<b<<endl;
    cout<<*(b)<<endl;
    
    vector<int> cde{1,1};
    cout<<&cde<<endl;
    if (cave[cde].empty() == false)
        cout<<"a;ng;lanw;g"<<*cave[cde].begin()<<endl;
    
    Initialize_Cave(cave);
    
    for (int r=1; r<=4; r++) {
        for (int c=1; c<=4; c++) {
            vector<int> rc{r, c};
            if (cave[rc].empty() == false)
                cout<<"cave square (1,1) contains a "<<*cave[rc].begin()<<endl;

            Print_Square(cave, rc);
        }
    }
    
    vector<string> cave_diagram;
    Get_Cave_Diagram(cave, cave_diagram);
    Print_Cave_Diagram(cave_diagram);
    
    return 0;
}

// add the player, ladder, wumpus, pits, gold, stench, breeze to the map
// input:
// output:
void Initialize_Cave(map<vector<int>, set<string> > &cave) {
    // place the "ladder" in row 1 column 1
    vector<int> rc{1,1};
    cave[rc].insert("ladder");
    // place the "player" at the same location as the ladder
    cave[rc].insert("player");
    // place the "wumpus" - can't be in the same square as the ladder
    
    // place the 3 "pits" - can't be in the same square as the ladder, wumpus, or another pit
    
    // place the "gold" - can't be in the same square as a pit or the ladder
    
    // place the "stench" squares to the left, right, up, and down from the wumpus
    
    // place the "breeze" squares to the left, right, up, and down from the three pits
    
}


// print the contents of the square
// input:
// output:
void Print_Square(map<vector<int>, set<string> > &cave, const vector<int> &rc) {
    
}

// build a vector of strings where each string in the vector represents one row of the cave output
// input:
// output:
void Get_Cave_Diagram(map<vector<int>, set<string> > &cave, vector<string> &cave_diagram) {
    int cell_rows = 5;
    int cell_columns = 11;
    int total_rows = cell_rows*4 + 1;
    int total_columns = cell_columns*4 + 1;
    
    // fill in with vertical cell divisions
    for (int r=0; r<total_rows; r++) {
        string row(total_columns, ' ');
        for (int c=0; c<total_columns; c+=cell_columns) {
            row[c] = '|';
        }
        cave_diagram.push_back(row);
    }
    
    // udpate horizontal rows with '-'
    for (int i=0; i<total_rows; i+=cell_rows) {
        cave_diagram[i] = string(total_columns, '-');
    }
    
    // update cell corners with '+'
    for (int r=0; r<total_rows; r+=cell_rows) {
        for (int c=0; c<total_columns; c+=cell_columns) {
            cave_diagram[r][c]='+';
        }
    }
    
    // replace the part of the string with the cell contents
    
}


