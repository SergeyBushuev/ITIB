using namespace std;

class Neural_network
{
private:
	double sum(int j, vector<double> & weights, int n);
	bool logisticAF(double net);
	double func(double net);
	double d_func(double net);
	bool learning(vector<tuple<int, bool>> & examples, vector <double> & weights);
	vector<double> _w = {0,0,0,0,0};
	void less(vector<tuple<int, bool>> & examples);
	int _n = 4;
	vector<tuple<int, bool>> _examples;
	bool _success;
	vector<tuple<int, bool>> _min;
	double _norma = 0.5;
public:
	void finding();
	void start_learning();
	Neural_network();
};
