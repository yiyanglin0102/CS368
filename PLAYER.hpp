#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <time.h>
#include <stdio.h>
#include <map>
#include "CAVE.hpp"
using namespace std;

class PLAYER{
    string facing = "right";
    int x;
    int y;
    vector<int> position;
    bool arrow = true;
    bool climb = false;
    bool gold = false;
    bool eaten = false;
    bool fell = false;
    bool wumpus_killed = false;
public:
    PLAYER();
    vector<int> Get_Position();
    string Get_Facing();
    vector<int> Get_Next_Square();
    bool Pickup_Gold(CAVE cave);
    bool Update_Player_Status(CAVE cave);
    bool Eaten();
    bool Fell();
    bool Has_Gold();
    bool Has_Arrow();
    bool Escaped();
    void Turn_Right();
    void Turn_Left();
    void Move_Forward();
    bool Climb_Ladder();
    bool Shoot_Arrow(CAVE cave);
};
#endif /* PLAYER_hpp */
