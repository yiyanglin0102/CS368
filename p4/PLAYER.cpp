/*******************************************************
 * Name: Yiyang Lin
 * Wisc ID: 9080288724
 * OS: macOS
 * IDE (or text editor): Xcode
 * Compiler: Xcode
 * How long did the assignment take you to complete in minutes: 1200
 * What other resources did you consult (copy and paste links below: online
 *******************************************************
 */

#include "PLAYER.hpp"
#include "CAVE.hpp"
#include <map>
using namespace std;

/**
 * Constructor of the class, initialize x, y and
 * position.
 */
PLAYER::PLAYER() {
	x = 1;
	y = 1;
	position = {x, y};
}

/**
 * Assessor method return position.
 */
vector<int> PLAYER::Get_Position() {
	return position;
}

/**
 * Assessor method return string facing.
 */
string PLAYER::Get_Facing() {
	return facing;
}

/**
 * Mutator method changing string facing to left
 * position.
 */
void PLAYER::Turn_Left() {
	if (facing == "up") {
		facing = "left";
	} else if (facing == "left") {
		facing = "down";
	} else if (facing == "right") {
		facing = "up";
	} else if (facing == "down") {
		facing = "right";
	}
}

/**
 * Mutator method changing string facing to right
 * position.
 */
void PLAYER::Turn_Right() {
	if (facing == "up") {
		facing = "right";
	} else if (facing == "down") {
		facing = "left";
	} else if (facing == "left") {
		facing = "up";
	} else if (facing == "right") {
		facing = "down";
	}
}

/**
 * Returns the coordinates of the square that the
 * player will step into if he or she move straight
 * forward.
 */
vector<int> PLAYER::Get_Next_Square() {
	vector<int> forwardPosition;

	if (facing == "right") {
		y++;
		forwardPosition = {x,y};
		y--;
	} else if (facing == "left") {
		y--;
		forwardPosition = {x,y};
		y++;
	} else if (facing == "up") {
		x--;
		forwardPosition = {x,y};
		x++;
	} else if (facing == "down") {
		x++;
		forwardPosition = {x,y};
		x--;
	}
	return forwardPosition;
}

/**
 * Changes the position of the player when player
 * steps forward one square.
 */
void PLAYER::Move_Forward() {
	if (facing == "right") {
		y++;
		position = {x, y};
	}
	else if(facing == "left")
	{
		y--;
		position = {x, y};
	}
	else if(facing == "up")
	{
		x--;
		position = {x, y};
	}
	else if(facing == "down")
	{
		x++;
		position = {x, y};
	}
}

/**
 * Returns true if player picks up gold.
 */
bool PLAYER::Pickup_Gold(CAVE &cave) {
	if (cave.Square_Contains_Gold(position)) {
		cave.Remove_Gold(position);
		gold = true;
		return true;
	}
	return false;
}

/**
 * Returns true if player kills the Wumpus.
 */
bool PLAYER::Shoot_Arrow(CAVE &cave) {

	arrow = false;
	if (facing == "right" && cave.Shoot_Square(Get_Next_Square())) {
		wumpus_killed = true;
		return true;
	}
	if (facing == "left" && cave.Shoot_Square(Get_Next_Square())) {
		wumpus_killed = true;
		return true;
	}
	if (facing == "up" && cave.Shoot_Square(Get_Next_Square())) {
		wumpus_killed = true;
		return true;
	}
	if (facing == "down" && cave.Shoot_Square(Get_Next_Square())) {
		wumpus_killed = true;
		return true;
	}
	return false;
}

/**
 * Returns true if player climbs.
 */
bool PLAYER::Climb_Ladder() {
	climb = true;
	return climb;
}

/**
 * Takes the cave data structure as a parameter.
 * If the player position is a square with a living
 * wumpus then the player is eaten. If the player
 * position is in a square with a pit then the player
 * falls into the pit. If the player is still alive at
 * the end of this turn the function returns true.
 * If the player has been eaten by the wumpus or has
 * fallen to his or her death then the function returns
 * false.
 */
bool PLAYER::Update_Player_Status(CAVE &cave) {
	if (cave.Is_Wumpus_Alive() && cave.Square_Contains_Living_Wumpus(position)
			&& wumpus_killed == false) {
		eaten = true;
		return false;
	}
	if (cave.Square_Contains_Pit(position)) {
		fell = true;
		return false;
	}
	return true;
}

/**
 * Returns true if the player has been eaten by the
 * wumpus.
 */
bool PLAYER::Eaten() {
	if (arrow == false && wumpus_killed == true) {
		return false;
	}
	return eaten;
}

/**
 * Returns true if the player has fallen into pit
 * while exploring the cave.
 */
bool PLAYER::Fell() {
	return fell;
}

/**
 * Returns true if the player has picked up the
 * gold.
 */
bool PLAYER::Has_Gold() {
	return gold;
}

/**
 * Returns true if the player still has the
 * arrow.
 */
bool PLAYER::Has_Arrow() {
	return arrow;
}

/**
 * Returns true if the player is alive and has
 * climbed the ladder to safety regardless of
 * whether they found the gold or not.
 */
bool PLAYER::Escaped() {
	return climb;
}
