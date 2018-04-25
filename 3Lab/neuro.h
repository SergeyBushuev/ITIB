#pragma once
#include <vector>
#include <iostream>

class n_net
{
public:
	n_net();
	n_net(double v0, double v1, double v2, double v3);
	~n_net();

	double func_phi(std::vector<int> X, std::vector<int> C);
	double func_net(std::vector<int> X);
	int func_y_net(double net);
	int func_delta(std::vector<int> X);
	int func_E();
	int study(std::vector<std::vector<int>> X);
	void printY();
	void printV();

	std::vector <std::vector<int>> C = { { 0,1,0,1 },{ 0,1,1,0 },{ 0,1,1,1 } }; // RBF вектора
	std::vector<double> V{ 0,0,0,0 }; // вектор весов
	std::vector<int> real_func{ 1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1 }; // Данный вектор БФ
	std::vector<std::vector<int>> all = { { 0,0,0,0 },{ 0,0,0,1 },{ 0,0,1,0 },{ 0,0,1,1 },
	{ 0,1,0,0 },{ 0,1,0,1 },{ 0,1,1,0 },{ 0,1,1,1 },
	{ 1,0,0,0 },{ 1,0,0,1 },{ 1,0,1,0 },{ 1,0,1,1 },
	{ 1,1,0,0 },{ 1,1,0,1 },{ 1,1,1,0 },{ 1,1,1,1 } }; // вектора наборов

};
