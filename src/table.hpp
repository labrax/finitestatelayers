
#pragma once

class Table {
private:
	int ** matrix;
	unsigned int size_x, size_y;
	
	int ** matrix_new;
	
	void start_aux();
	
public:
	Table(char * file);
	Table(unsigned int x, unsigned int y);
	~Table();
	
	void print();
	
	unsigned int getSizeX();
	unsigned int getSizeY();
	
	int getElement(int x, int y);
	int getElementFrom(int dest_x, int dest_y, int x, int y);
	
	int getAmount(int elem, int src_x, int src_y, unsigned int neighbour_8_dist);
	
	void setNextElement(int x, int y, int val);
	void finishIteration();
};
