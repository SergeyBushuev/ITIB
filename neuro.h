#pragma once
#include <vector>
#include <stack>

using namespace std;

class n_net
{
private:
	vector<int> B = { 1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1 };
	vector<int> Y = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	vector<bool> miss = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	vector<double> w = { 0,0,0,0,0 };
	vector<vector<int>> examples = {
		{ 1,0,0,0,0 }, { 1,0,0,0,1 }, { 1,0,0,1,0 }, { 1,0,0,1,1 },
		{ 1,0,1,0,0 }, { 1,0,1,0,1 }, { 1,0,1,1,0 }, { 1,0,1,1,1 },
		{ 1,1,0,0,0 }, { 1,1,0,0,1 }, { 1,1,0,1,0 }, { 1,1,0,1,1 },
		{ 1,1,1,0,0 }, { 1,1,1,0,1 }, { 1,1,1,1,0 }, { 1,1,1,1,1 }
	};
	bool learning();
	bool AF(double net);
	bool logisticAF(double net);
	double func(double net);
	double n = 0.5;
	double net(int l);
	double d_func(double net);
public:
	void start_learning();
	n_net() {};
	void print(vector<int> v);
	void print(vector<double> v);

};
