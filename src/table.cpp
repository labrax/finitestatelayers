
#include "table.hpp"
#include <iostream>
#include <cstdio>

Table::Table(char * file) {
	FILE * fp;
	fp = fopen(file, "r");
	
	fscanf(fp, "%u %u", &(this->size_x), &(this->size_y));
	this->matrix = new int *[size_y];
	
	unsigned int i, j, elem;
	for(j=0; j<size_y; j++) {
		this->matrix[j] = new int[size_x];
		for(i=0; i<size_x; i++) {
			fscanf(fp, " %u", &elem);
			matrix[j][i] = elem;
		}
	}
	start_aux();
}

Table::Table(unsigned int x, unsigned int y) {
	this->size_x = x;
	this->size_y = y;
	
	this->matrix = new int *[size_y];
	
	unsigned int i, j;
	for(j=0; j<size_y; j++) {
		this->matrix[j] = new int[size_x];
		for(i=0; i<size_x; i++) {
			matrix[j][i] = 0;
		}
	}
	start_aux();
}

Table::~Table() {
	unsigned int i;
	for(i=0; i<size_y; i++) {
		delete(matrix[i]);
		delete(matrix_new[i]);
	}
	delete(matrix);
	delete(matrix_new);
}

void Table::start_aux() {
	this->matrix_new = new int *[size_y];
	
	unsigned int i, j;
	for(j=0; j<size_y; j++) {
		this->matrix_new[j] = new int[size_x];
		for(i=0; i<size_x; i++) {
			matrix_new[j][i] = 0;
		}
	}
}

void Table::print() {
	unsigned int j, i;
	for(j=0; j<size_y; j++) {
		for(i=0; i<size_x; i++) {
			if(matrix[j][i] == 1)
				std::cout << 'X' << " ";
			else
				std::cout << matrix[j][i] << " ";
		}
		std::cout << std::endl;
	}
}

unsigned int Table::getSizeX() {
	return size_x;
}

unsigned int Table::getSizeY() {
	return size_y;
}

int Table::getElement(int x, int y) {
	if(x >= 0 && x < size_x)
		if(y >= 0 && y < size_y)
			return matrix[y][x];
	return 0;
}

int Table::getElementFrom(int dest_x, int dest_y, int x, int y) {
	return getElement(x+dest_x, y+dest_y);
}

int Table::getAmount(int elem, int src_x, int src_y, unsigned int neighbour_8_dist) {
	int count = 0;
	
	if(neighbour_8_dist == 0)
		return 0;
	
	int y, x;
	for(y=src_y-(int) neighbour_8_dist; y<=src_y+(int)neighbour_8_dist; y++) {
		for(x=src_x-(int)neighbour_8_dist; x<=src_x+(int)neighbour_8_dist; x++) {
			//std::cout << "(" << x << "," << y << ") is " << getElement(x, y) << std::endl;
			if(x == src_x && y == src_y);
			else if(getElement(x, y) == elem)
				count++;
		}
	}
	//std::cout << std::endl;
	return count;
}

void Table::setNextElement(int x, int y, int val) {
	matrix_new[y][x] = val;
}

void Table::finishIteration() {
	unsigned int j, i;
	for(j=0; j<size_y; j++) {
		for(i=0; i<size_x; i++) {
			matrix[j][i] = matrix_new[j][i];
		}
	}
}
