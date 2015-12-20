/*
 * Move.cpp
 *
 *  Created on: Dec 20, 2015
 *      Author: perham
 */

#include "Move.h"

void Move::setMove(int xs, int ys, int xd, int yd, Board p) {
	moveArray[0] = xs;
	moveArray[1] = ys;
	moveArray[2] = xd;
	moveArray[3] = yd;
	position = p;
}

Board Move::doMove(int checkMove) {
	Board newPosition;
	newPosition = position;

	if (checkMove) {

		newPosition.erase(moveArray[0], moveArray[1]);
		newPosition.put(moveArray[2], moveArray[3]);
	}

	return newPosition;
}

Move::Move() {
	int i;
	for (i = 0; i < 4; i++)
		moveArray[i] = 0;
}

Move::~Move() {
	// TODO Auto-generated destructor stub
}

