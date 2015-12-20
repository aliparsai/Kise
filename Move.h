/*
 * Move.h
 *
 *  Created on: Dec 20, 2015
 *      Author: perham
 */

#ifndef MOVE_H_
#define MOVE_H_

class Move {

private:
	int moveArray[4];
	Board position;
public:
	void setMove(int, int, int, int, Board);
	Board doMove(int);

	Move();
	virtual ~Move();
};

#endif /* MOVE_H_ */
