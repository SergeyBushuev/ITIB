
#include "stdafx.h"
#include "neuro.h"
#include <string>
#include <vector>
#include <iostream>


int main(int argc, char *argv[]) {
	std::vector<std::vector<int>> min1 = { { 0,1,0,0 },{ 1,1,1,0 },{ 0,0,0,0 },{ 1,0,0,0 },{ 1,0,0,1 } };
	std::vector<std::vector<int>> study_vectors = { { 0,0,0,0 },{ 0,0,0,1 },{ 0,0,1,0 },{ 0,0,1,1 },
	{ 0,1,0,0 },{ 0,1,0,1 },{ 0,1,1,0 },{ 0,1,1,1 },
	{ 1,0,0,0 },{ 1,0,0,1 },{ 1,0,1,0 },{ 1,0,1,1 },
	{ 1,1,0,0 },{ 1,1,0,1 },{ 1,1,1,0 },{ 1,1,1,1 } }; // Все комбинации вектора Х

	n_net neur;
	neur.study(min1);

	int pause;
	std::cin >> pause;
	return 0;
}

