#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <time.h>      // time
#include <cstdlib>
using namespace std;

// don't change this function
// purpose: prints a map of the cave to the console
// input: the printable map a vector of strings
// output: none - console output of the cave diagram
void Print_Cave_Diagram(const vector<string> &cave_diagram){
    for (auto s : cave_diagram)
        cout<<s <<endl;
}

// Implement these functions below
// Do not change the function prototpyes
void Initialize_Cave(map<vector<int>, set<string> > &cave);
void Print_Square(map<vector<int>, set<string> > &cave);
void Get_Cave_Diagram(map<vector<int>, set<string> > &cave, vector<string> &cave_diagram);

// sample main function
int main() {
    
    map<vector<int>, set<string> > cave;
    Initialize_Cave(cave);
    Print_Square(cave);
    vector<string> cave_diagram;
    Get_Cave_Diagram(cave, cave_diagram);
    Print_Cave_Diagram(cave_diagram);
    
    return 0;
}

// add the player, ladder, wumpus, pits, gold, stench, breeze to the map
// input:
// output:
void Initialize_Cave(map<vector<int>, set<string> > &cave) {
    srand(time(NULL));
    // place the "ladder" in row 1 column 1
    
    cave[{1,1}].insert("ladder");
    
    // place the "player" at the same location as the ladder
    cave[{1,1}].insert("player");
    
    // place the "wumpus" - can't be in the same square as the ladder
    int random1 = 2+(rand()%3);
    int random2 = 2+(rand()%3);
    cave[{random1,random2}].insert("wumpus");
    
    // place the 3 "pits" - can't be in the same square as the ladder, wumpus, or another pit
    int random3 = 2+(rand()%3);
    int random4 = 2+(rand()%3);
    int random5 = 2+(rand()%3);
    int random6 = 2+(rand()%3);
    int random7 = 2+(rand()%3);
    int random8 = 2+(rand()%3);
    
    
    while(random1 == random3 && random2 == random4)
    {
        random3 = 2+(rand()%3);
        random4 = 2+(rand()%3);
    }
    cave[{random3,random4}].insert("pit");
    
    while(random3 == random5 && random4 == random6)
    {
        random5 = 2+(rand()%3);
        random6 = 2+(rand()%3);
    }
    cave[{random5,random6}].insert("pit");
    
    while(random5 == random7 && random6 == random8)
    {
        random7 = 2+(rand()%3);
        random8 = 2+(rand()%3);
    }
    cave[{random7,random8}].insert("pit");
    // place the "gold" - can't be in the same square as a pit or the ladder
    int random9 = 2+(rand()%3);
    int random10 = 2+(rand()%3);
    
    while((random9 == random3 && random10 == random4) || (random9 == random5 && random10 == random6) || (random9 == random7 && random10 == random8))
    {
        random9 = 2+(rand()%3);
        random10 = 2+(rand()%3);
    }
    
    cave[{random9,random10}].insert("gold");
    // place the "stench" squares to the left, right, up, and down from the wumpus
    
    cave[{random1,random2+1}].insert("stench");
    cave[{random1,random2-1}].insert("stench");
    cave[{random1-1,random2}].insert("stench");
    cave[{random1+1,random2}].insert("stench");
    
    // place the "breeze" squares to the left, right, up, and down from the three pits
    
    cave[{random3,random4+1}].insert("breeze");
    cave[{random3,random4-1}].insert("breeze");
    cave[{random3-1,random4}].insert("breeze");
    cave[{random3+1,random4}].insert("breeze");
    
    cave[{random5,random6+1}].insert("breeze");
    cave[{random5,random6-1}].insert("breeze");
    cave[{random5-1,random6}].insert("breeze");
    cave[{random5+1,random6}].insert("breeze");
    
    cave[{random7,random8+1}].insert("breeze");
    cave[{random7,random8-1}].insert("breeze");
    cave[{random7-1,random8}].insert("breeze");
    cave[{random7+1,random8}].insert("breeze");
}


// print the contents of the square
// input:
// output:
void Print_Square(map<vector<int>, set<string> > &cave) {
    
    for (int r=1; r<=4; r++) {
        for (int c=1; c<=4; c++) {
            cout << r<< ", "<< c << endl;
            cout << "This part of the cave contains" << endl;
            
            if(cave[{r,c}].empty() != false)
            {
                cout<<"    nothing"<<endl<<endl;
            }
            
            if (cave[{r,c}].empty() == false)
            {
                for(set<string>::iterator it = cave[{r,c}].begin(); it != cave[{r,c}].end(); it++)
                {
                    cout<<"    "<<*it<<endl;
                }
                cout<<endl;
            }
        }
        
    }
    
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
    
    for (int c=1; c<=4; c++)
    {
        for (int r=1; r<=4; r++)
        {
            
            for(set<string>::iterator it = cave[{r,c}].begin(); it != cave[{r,c}].end(); it++)
            {
                string word = *it;
                
                for(int i=0; i< word.length(); i++)
                {
                    char letter = word.at(i);
                    
                    if(r == 1 && c == 1)
                    {
                        if(cave_diagram[2].at(3+i) != ' ')
                        {
                            cave_diagram[3].at(3+i) = letter;
                        }
                        else if(cave_diagram[1].at(3+i) != ' ')
                        {
                            cave_diagram[2].at(3+i) = letter;
                        }
                        else
                            cave_diagram[1].at(3+i) = letter;
                    }
                    if(r == 1 && c == 2)
                    {
                        if(cave_diagram[2].at(14+i) != ' ')
                        {
                            cave_diagram[3].at(14+i) = letter;
                        }
                        else if(cave_diagram[1].at(14+i) != ' ')
                        {
                            cave_diagram[2].at(14+i) = letter;
                        }
                        else
                            cave_diagram[1].at(14+i) = letter;
                    }
                    if(r == 1 && c == 3)
                    {
                        if(cave_diagram[2].at(25+i) != ' ')
                        {
                            cave_diagram[3].at(25+i) = letter;
                        }
                        else if(cave_diagram[1].at(25+i) != ' ')
                        {
                            cave_diagram[2].at(25+i) = letter;
                        }
                        else
                            cave_diagram[1].at(25+i) = letter;
                    }
                    if(r == 1 && c == 4)
                    {
                        if(cave_diagram[2].at(36+i) != ' ')
                        {
                            cave_diagram[3].at(36+i) = letter;
                        }
                        else if(cave_diagram[1].at(36+i) != ' ')
                        {
                            cave_diagram[2].at(36+i) = letter;
                        }
                        else
                            cave_diagram[1].at(36+i) = letter;
                    }
                    if(r == 2 && c == 1)
                    {
                        if(cave_diagram[7].at(3+i) != ' ')
                        {
                            cave_diagram[8].at(3+i) = letter;
                        }
                        else if(cave_diagram[6].at(3+i) != ' ')
                        {
                            cave_diagram[7].at(3+i) = letter;
                        }
                        else
                            cave_diagram[6].at(3+i) = letter;
                    }
                    if(r == 2 && c == 2)
                    {
                        if(cave_diagram[7].at(14+i) != ' ')
                        {
                            cave_diagram[8].at(14+i) = letter;
                        }
                        else if(cave_diagram[6].at(14+i) != ' ')
                        {
                            cave_diagram[7].at(14+i) = letter;
                        }
                        else
                            cave_diagram[6].at(14+i) = letter;
                    }
                    if(r == 2 && c == 3)
                    {
                        if(cave_diagram[7].at(25+i) != ' ')
                        {
                            cave_diagram[8].at(25+i) = letter;
                        }
                        else if(cave_diagram[6].at(25+i) != ' ')
                        {
                            cave_diagram[7].at(25+i) = letter;
                        }
                        else
                            cave_diagram[6].at(25+i) = letter;
                    }
                    if(r == 2 && c == 4)
                    {
                        if(cave_diagram[7].at(36+i) != ' ')
                        {
                            cave_diagram[8].at(36+i) = letter;
                        }
                        else if(cave_diagram[6].at(36+i) != ' ')
                        {
                            cave_diagram[7].at(36+i) = letter;
                        }
                        else
                            cave_diagram[6].at(36+i) = letter;
                    }
                    if(r == 3 && c == 1)
                    {
                        if(cave_diagram[12].at(3+i) != ' ')
                        {
                            cave_diagram[13].at(3+i) = letter;
                        }
                        else if(cave_diagram[11].at(3+i) != ' ')
                        {
                            cave_diagram[12].at(3+i) = letter;
                        }
                        else
                            cave_diagram[11].at(3+i) = letter;
                    }
                    if(r == 3 && c == 2)
                    {
                        if(cave_diagram[12].at(14+i) != ' ')
                        {
                            cave_diagram[13].at(14+i) = letter;
                        }
                        else if(cave_diagram[11].at(14+i) != ' ')
                        {
                            cave_diagram[12].at(14+i) = letter;
                        }
                        else
                            cave_diagram[11].at(14+i) = letter;
                    }
                    if(r == 3 && c == 3)
                    {
                        if(cave_diagram[12].at(25+i) != ' ')
                        {
                            cave_diagram[13].at(25+i) = letter;
                        }
                        else if(cave_diagram[11].at(25+i) != ' ')
                        {
                            cave_diagram[12].at(25+i) = letter;
                        }
                        else
                            cave_diagram[11].at(25+i) = letter;
                    }
                    if(r == 3 && c == 4)
                    {
                        if(cave_diagram[12].at(36+i) != ' ')
                        {
                            cave_diagram[13].at(36+i) = letter;
                        }
                        else if(cave_diagram[11].at(36+i) != ' ')
                        {
                            cave_diagram[12].at(36+i) = letter;
                        }
                        else
                            cave_diagram[11].at(36+i) = letter;
                    }
                    if(r == 4 && c == 1)
                    {
                        if(cave_diagram[17].at(3+i) != ' ')
                        {
                            cave_diagram[18].at(3+i) = letter;
                        }
                        else if(cave_diagram[16].at(3+i) != ' ')
                        {
                            cave_diagram[17].at(3+i) = letter;
                        }
                        else
                            cave_diagram[16].at(3+i) = letter;
                    }
                    if(r == 4 && c == 2)
                    {
                        if(cave_diagram[17].at(14+i) != ' ')
                        {
                            cave_diagram[18].at(14+i) = letter;
                        }
                        else if(cave_diagram[16].at(14+i) != ' ')
                        {
                            cave_diagram[17].at(14+i) = letter;
                        }
                        else
                            cave_diagram[16].at(14+i) = letter;
                    }
                    if(r == 4 && c == 3)
                    {
                        if(cave_diagram[17].at(25+i) != ' ')
                        {
                            cave_diagram[18].at(25+i) = letter;
                        }
                        else if(cave_diagram[16].at(25+i) != ' ')
                        {
                            cave_diagram[17].at(25+i) = letter;
                        }
                        else
                            cave_diagram[16].at(25+i) = letter;
                    }
                    if(r == 4 && c == 4)
                    {
                        if(cave_diagram[17].at(36+i) != ' ')
                        {
                            cave_diagram[18].at(36+i) = letter;
                        }
                        else if(cave_diagram[16].at(36+i) != ' ')
                        {
                            cave_diagram[17].at(36+i) = letter;
                        }
                        else
                            cave_diagram[16].at(36+i) = letter;
                    }
                }
            }
        }
    }
    
}
