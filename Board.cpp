/*
 * Board.cpp
 *
 *  Created on: Dec 20, 2015
 *      Author: perham
 */

#include "Board.h"
#include <iostream>

Board::Board() {
	board = 0;
}

void Board::put(int x, int y) {
	board = (uint64_t) board | ((uint64_t) 1 << (8 * x + y));
}

int Board::get(int x, int y) {
	int r = 0;
	r = (uint64_t) ((uint64_t) board >> (8 * x + y)) & 1;
	return r;
}

void Board::erase(int x, int y) {
	board = (uint64_t) board & ~((uint64_t) 1 << (8 * x + y));
}

void Board::show() {
	int i, j;

	for (i = 7; i >= 0; i--) {
		for (j = 0; j < 8; j++) {
			std::cout << get(i, j);

		}
		std::cout << "\n";
	}

}

Board & Board::operator =(Board x) {
	board = x.board;
	return *this;
}

void Board::toArray(char **arr) {
	int i, j;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			arr[i][j] = get(i, j);
}

Board::~Board() {
}

int Board::popCount(int lookupTable[]) {
	if (board == 0)
		return 0;

	else if ((board & (board - 1)) == 0)
		return 1;

	unsigned char * byteAccess = (unsigned char *) &board;
	return lookupTable[byteAccess[0]] + lookupTable[byteAccess[1]]
			+ lookupTable[byteAccess[2]] + lookupTable[byteAccess[3]]
			+ lookupTable[byteAccess[4]] + lookupTable[byteAccess[5]]
			+ lookupTable[byteAccess[6]] + lookupTable[byteAccess[7]];
}
