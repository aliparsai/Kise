/*
 * Board.h
 *
 *  Created on: Dec 20, 2015
 *      Author: perham
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <cstdint>

class Board {
private:
	uint64_t board;

public:
	Board();
	virtual ~Board();
	void put(int, int);
	int get(int, int);
	void erase(int, int);
	void show();
	Board & operator =(Board);
	void toArray(char**);
	int popCount(int[]);
};

#endif /* BOARD_H_ */
