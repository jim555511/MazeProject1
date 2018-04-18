#ifndef Robot_h
#define Robot_h

#include "Point.h"
#include "Maze.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

class Robot {


public:
	Robot() {
		CP.setY(0);
		CP.setX(2);
		oldP.push_back(CP);
		TempC = 0;

	}
	Robot(Point P1) {
		CP = P1;

	}
	//Checks for intersections left and right
	bool InLR(Maze M1) {
		int X = CP.getX();
		int Y = CP.getY();
		if ((M1.getVal(X, Y + 1) == ' ' && M1.getVal(X, Y - 1) == ' ' && M1.getVal(X - 1, Y) == ' ') || (M1.getVal(X, Y + 1) == ' ' && M1.getVal(X, Y - 1) == ' ' && M1.getVal(X + 1, Y) == ' ')) {
			return true;
		}
		else {
			return false;
		}
	}

	//Checks for intersections up and down
	bool InUD(Maze M1) {
		int X = CP.getX();
		int Y = CP.getY();
		if ((M1.getVal(X+1, Y) == ' ' && M1.getVal(X-1, Y) == ' ' && M1.getVal(X, Y + 1) == ' ') || (M1.getVal(X + 1, Y) == ' ' && M1.getVal(X - 1, Y) == ' ' && M1.getVal(X, Y - 1) == ' ')) {
			return true;
		}
		else {
			return false;
		}
	}

	//Checks for a four way intersection
	bool InFour(Maze M1) {
		if (InUD(M1) && InLR(M1)) {
			return true;
		}
		return false;
	}

	//Checks for a deadend to the left and Right
	/*bool DeadEndLR(Maze M1) {
		int X = CP.getX();
		int Y = CP.getY();
		if ((M1.getVal(X, Y + 1) == '%' && M1.getVal(X, Y - 1) == '%' && M1.getVal(X - 1, Y) == '%') || (M1.getVal(X, Y + 1) == '%' && M1.getVal(X, Y - 1) == '%' && M1.getVal(X + 1, Y) == '%')) {
			return true;
		}
		else {
			return false;
		}
	}

	//Checks for a dead end up and down, m
	/*bool DeadEndUD(Maze M1) {
		int X = CP.getX();
		int Y = CP.getY();
		if ((M1.getVal(X + 1, Y) == '%' && M1.getVal(X - 1, Y) == '%' && M1.getVal(X, Y + 1) == '%') || (M1.getVal(X + 1, Y) == '%' && M1.getVal(X - 1, Y) == '%' && M1.getVal(X, Y - 1) == '%')) {
			return true;
		}
		else {
			return false;
		}
	}*/
	
	

	//Functions that do stuff
	bool Isold(int Count, int X, int Y);
	bool IsInter(Maze M1);
	void Intersect();
	void Dead(Maze M1);
	void SetCurrentPoint(Maze Maze1);
	
	vector<Point> GetOldP(){
		return oldP;
	}


private:
	Point CP;
	vector<Point> oldP;
	int TempC;
	vector<Point> Intersections;







};









#endif
