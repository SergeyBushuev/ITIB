#include "stdafx.h"
#include "neuro.h"
#include <cmath>
#include <bitset>
#include <iostream>

using namespace std;


bool n_net::learning()
{
	cout << "learning stars";
	int epoch = 0;
	int E = 0;
	double dw;
	for (size_t i =0; i < B.size(); i++)
	{
		if (B[i] != Y[i]) {
			E++;
			miss[i] = 1;
		}
		else {
			miss[i] = 0;
		}
	}
	bool flag = false;
	while (flag != true) {
		if (epoch > 40) return false;
		cout << "epoch #" << epoch << " start \n";
		E = 0;
		for (size_t l = 0; l < examples.size(); l++)
		{
			for (size_t i = 0; i < examples[l].size(); i++)
			{
				dw = n * miss[l] * d_func(net(l)) * examples[l][i];
				w[i] = w[i] + dw;
			}

		}

		for (size_t l = 0; l < examples.size(); l++) {
			Y[l] = logisticAF(net(l));

			if (B[l] != Y[l]) {
				E++;
				miss[l] = 1;
			}
			else {
				miss[l] = 0;
			}
		}
		cout << "Epoch = " << epoch << "; ";
		print(w);
		print(Y);
		if (E == 0) flag = true;
		epoch++;
	}
	return true;
}

void n_net::print(vector<int> v)
{
	cout << "Y = {";
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << "} \n";
}

void n_net::print(vector<double> v)
{
	cout << "W = {";
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << "} \n";
}

void n_net::start_learning()
{
	learning();
}

double n_net::net(int l)
{
	double sum = 0;
	for (size_t i = 1; i < 4; i++)
	{
		sum = w[i] * examples[l][i] + w[0];
	}
	return sum;
}

bool n_net::AF(double net)
{
	return (net >= 0) ? 1 : 0;
}

bool n_net::logisticAF(double net)
{
	return (func(net) >= 0.5) ? 1 : 0;
}

double n_net::func(double net)
{
	return 0.5*(tanh(net) + 1);
}
double n_net::d_func(double net)
{
	return 2 / (pow((std::exp(net) + std::exp(-net)), 2));
}
