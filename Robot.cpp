#include "Maze.h"
#include "Point.h"
#include "Robot.h"
#include "Intersection.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

//Returns false if it is an old point
bool Robot::Isold(int Count, int X, int Y) {
	int times = 0;
	for (int i = 0; i < oldP.size(); i++) {
		if (oldP.at(i).getX() == X && oldP.at(i).getY() == Y) {
			times++;
		}
	}
	if (times >= 1) {
		return false;
	}
	else {
		return true;
	}
}

//Returns true if it is an intersection
bool Robot::IsInter(Maze M1) {
	int X = CP.getX();
	int Y = CP.getY();
	if (InLR(M1) || InUD(M1) || InFour(M1)) {
		return true;
	}
	else {
		return false;
	}
}

//If it's an intersection we add it to a vector for dead ends and make sure it isn't just an intersection we've been pushed back to
void Robot::Intersect() {
	int temp = 0;
	for (int i = 0; i < Intersections.size(); i++) {
		if (Intersections.at(i).getX() == CP.getX() && Intersections.at(i).getY() == CP.getY()) {
			temp++;
		}
	}
	if (temp > 0) {
	}
	else {
		Intersections.push_back(CP);
		TempC++;
	}
}
//Moves CP back to intersection which the robot will not move down since it is an old point
void Robot::Dead(Maze M1) {
	CP = Intersections.at(TempC-1);
	Intersections.erase(Intersections.begin() + (TempC - 1));
	TempC--;
}

void Robot::SetCurrentPoint(Maze Maze1) {
	int Count = 0;

	// Makes sure that it goes until the end (I know the If statements are long, just bear with me)
	while (Maze1.getVal(CP.getX(), CP.getY()) != 'F') {
		//Checks three things: that the Robot doesn't go back on itself and that the robot moves to an open space and if it's an intersection
		if (IsInter(Maze1)) {
			Intersect();
		}
		//Right
		if ((Maze1.getVal(CP.getX() + 1, CP.getY()) == ' ' || Maze1.getVal(CP.getX() + 1, CP.getY()) == 'F') && Isold(Count, CP.getX() + 1,CP.getY())) {
			CP.setX(CP.getX() + 1);
			oldP.push_back(CP);
		}
		//Up
		else if ((Maze1.getVal(CP.getX(), CP.getY() + 1) == ' ' || Maze1.getVal(CP.getX(), CP.getY() + 1) == 'F') && Isold(Count, CP.getX(), CP.getY() + 1)) {
			CP.setY(CP.getY() + 1);
			oldP.push_back(CP);
		}
		//Left
		else if ((Maze1.getVal(CP.getX() - 1, CP.getY()) == ' ' || Maze1.getVal(CP.getX() - 1, CP.getY()) == 'F') && Isold(Count, CP.getX() - 1, CP.getY())) {
			CP.setX(CP.getX() - 1);
			oldP.push_back(CP);
		}
		//Down
		else if ((Maze1.getVal(CP.getX(), CP.getY() - 1) == ' ' || Maze1.getVal(CP.getX(), CP.getY() - 1) == 'F') && Isold(Count, CP.getX(), CP.getY() - 1)) {
			CP.setY(CP.getY() - 1);
			oldP.push_back(CP);
		}
		//DeadEnd
		else{
			Dead(Maze1);
		}
		Count++;
	}
	if (Maze1.getVal(CP.getX(), CP.getY()) == 'F') {
		cout << "Woohoo you won yay! good job, pat on the back" << endl;
	}
}