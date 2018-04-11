using namespace std;

bool Neural_network::logisticAF(double net)
{
	if (func(net) >= 0.5) {
		return 1;
	} else {
		return 0;
	}
}

double Neural_network::func(double net)
{
	return 0.5*(tanh(net) + 1);
}
double Neural_network::d_func(double net)
{
	return 2 / (pow((std::exp(net) + std::exp(-net)), 2));
}



double Neural_network::sum(int j, vector<double> & w, int n)
{
	std::bitset<16> bit(j);
	double net = 0;
	for (int i = 0; i < n; i++)
		net += w[i] * bit[i];
	net += w[n]; 
	return net;
}


bool Neural_network::learning(vector<tuple<int, bool>> & examples, vector <double> & w)
{
	cout << "learning starts\n";
	double net;
	double delta;
	bool y; 
	int epoch = 0, err = 1;
	while (err != 0)
	{	
		if (epoch > 40) { 
			return false;
		}
		err = 0;
		cout << "epoch " << epoch << ":   ";

		vector<double> w_start = w;

		for (int j = 0; j < examples.size(); j++)
		{
			net = sum(get<0>(examples[j]), w, _n);
			y = logisticAF(net);
			cout << logisticAF(sum(get<0>(examples[j]), w_start, _n)) << " ";

			if (y != get<1>(examples[j]))
			{
				err++;
				std::bitset <16> bit(j);

				for (int i = 0; i < _n; i++)  
				{
					delta = _norma * (get<1>(examples[j]) - y) * bit[i] * d_func(net);
					w[i] = w[i] + delta;
				}
				w[_n] = w[_n] + _norma * (get<1>(examples[j]) - y) * d_func(net); 

			}
		}

		cout << " E = " << err << " w(";
		for (int i = _n; i > 0; i--) cout << w_start[i] << ",";
		cout << w_start[0] << ")" << endl;
		epoch++;
	}
	return true;
}


void Neural_network::finding()
{
	_min = _examples;
	less(_examples);
	cout << "\n\nminimal combination is\n\n";
	for (auto & ex : _min)
		cout << get<0>(ex) << " -> " << get<1>(ex) << endl;
}

void Neural_network::less(vector<tuple<int, bool>> & examples)
{
	for (int i = examples.size() - 1; i >= 0; i--)
	{
		vector<double> local_weights = this->_w;
		vector<tuple<int, bool>> local_examples = examples;
		local_examples.erase(local_examples.begin() + i);

		_success = learning(local_examples, local_weights);

		if (_success)
			for (auto & ex : _examples)
			{
				bool y = logisticAF(sum(get<0>(ex), local_weights, _n)); //  !!!
				if (y != get<1>(ex))
				{
					_success = false; break;
				}
			}

		if (_success)
		{
			if (local_examples.size() <= _min.size())
				_min = local_examples;
			less(local_examples);
		}
	}
}

void Neural_network::start_learning()
{
	vector<double> weights = this->_w;
	learning(this->_examples, weights);
}

Neural_network::Neural_network()
{
	for (int i = 0; i <= _n; i++)
		_w.push_back(0);
	for (int i = 0; i < 16; i++)
	{
		if (i != 5 && i != 6 && i != 7) {
			_examples.push_back(tuple<int, bool>(i, 1));
		}
		else {
			_examples.push_back(tuple<int, bool>(i, 0));
		}
	}
}
