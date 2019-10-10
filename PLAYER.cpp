#include "PLAYER.hpp"
#include "CAVE.hpp"
#include <map>
using namespace std;

PLAYER::PLAYER() {
    x = 1;
    y = 1;
    position = { x, y };
}

vector<int> PLAYER::Get_Position() {
    return position;
}
string PLAYER::Get_Facing() {
    return facing;
}
void PLAYER::Turn_Left() {
    if(facing == "up")
    {
        facing = "left";
    }
    else if(facing == "left")
    {
        facing = "down";
    }
    else if(facing == "right")
    {
        facing = "up";
    }
    else if(facing == "down")
    {
        facing = "right";
    }
}

void PLAYER::Turn_Right() {
    if(facing == "up")
    {
        facing = "right";
    }
    else if(facing == "down")
    {
        facing = "left";
    }
    else if(facing == "left")
    {
        facing = "up";
    }
    else if(facing == "right")
    {
        facing = "down";
    }
}

vector<int> PLAYER::Get_Next_Square()
{
    vector<int> forwardPosition;
    
    if(facing == "right")
    {
        y++;
        forwardPosition = {x,y};
        y--;
    }
    else if(facing == "left")
    {
        y--;
        forwardPosition = {x,y};
        y++;
    }
    else if(facing == "up")
    {
        x--;
        forwardPosition = {x,y};
        x++;
    }
    else if(facing == "down")
    {
        x++;
        forwardPosition = {x,y};
        x--;
    }
    return forwardPosition;
}

void PLAYER::Move_Forward()
{
    if(facing == "right")
    {
        y++;
        position = { x, y };
    }
    else if(facing == "left")
    {
        y--;
        position = { x, y };
    }
    else if(facing == "up")
    {
        x--;
        position = { x, y };
    }
    else if(facing == "down")
    {
        x++;
        position = { x, y };
    }
}

bool PLAYER::Pickup_Gold(CAVE cave) {
    if(cave.Square_Contains_Gold(position))
    {
        cave.Remove_Gold(position);
        gold = true;
        return true;
    }
    return false;
}
 ///// reference??
bool PLAYER::Shoot_Arrow(CAVE cave) {
    
    arrow = false;
    if(facing == "right" && cave.Shoot_Square(Get_Next_Square()))
    {
        wumpus_killed = true;
        return true;
    }
    if(facing == "left" && cave.Shoot_Square(Get_Next_Square()))
    {
        wumpus_killed = true;
        return true;
    }
    if(facing == "up" && cave.Shoot_Square(Get_Next_Square()))
    {
        wumpus_killed = true;
        return true;
    }
    if(facing == "down" && cave.Shoot_Square(Get_Next_Square()))
    {
        wumpus_killed = true;
        return true;
    }
    return false;
}

bool PLAYER::Climb_Ladder() {
    climb = true;
    return climb;
}

bool PLAYER::Update_Player_Status(CAVE cave) {
    if(cave.Is_Wumpus_Alive() && cave.Square_Contains_Living_Wumpus(position) && wumpus_killed == false)
    {
        eaten = true;
        return false;
    }
    if(cave.Square_Contains_Pit(position))
    {
        fell = true;
        return false;
    }
    return true;
}
bool PLAYER::Eaten() {
    if(arrow == false && wumpus_killed == true)
    {
        return false;
    }
    return eaten;
}
bool PLAYER::Fell() {
    return fell;
}
bool PLAYER::Has_Gold() {
    return gold;
}
bool PLAYER::Has_Arrow() {
    return arrow;
}
bool PLAYER::Escaped() {
    return climb;
}
