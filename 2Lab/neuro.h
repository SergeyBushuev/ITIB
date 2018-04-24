#pragma once
#include <vector>
#include <iostream>

class n_net
{
public:
	n_net();
	n_net(double w0, double w1, double w2, double w3, double w4);
	~n_net();

	void get_real_func();
	double func_delta(double real, double neur);
	double func_E();
	double study(int k);
	void work();
	void printW();

	std::vector<double> W{ 0,0,0,0,0 }; // Вектор весов
	std::vector<double> real_func; // Реальные значения функции функция
	std::vector<double> neur_func; // Смоделированные значения функции
};
