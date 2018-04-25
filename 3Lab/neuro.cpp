#include "stdafx.h"
#include "neuro.h"

n_net::n_net() {}

n_net::n_net(double v0, double v1, double v2, double v3) { // веса
	V[0] = v0;
	V[1] = v1;
	V[2] = v2;
	V[3] = v3;
}

n_net::~n_net() {}

double n_net::func_phi(std::vector<int> X, std::vector<int> C) { //функция phi
	double phi = 0;
	for (size_t i = 0; i < X.size(); i++) {
		phi += pow((X[i] - C[i]), 2);
	}
	phi = exp(-phi);
	return phi;
}

double n_net::func_net(std::vector<int> X) { // Считаем сетевой(комбинированный) вход
	double net = 0;
	for (size_t i = 0; i < C.size(); i++) {
		net += V[i + 1] * func_phi(X, C[i]);
	}
	net += V[0];
	return net;
}

int n_net::func_y_net(double net) { // Реальный выход нейросети
	if (net >= 0) {
		return 1;
	}
	else {
		return 0;
	}
}



int n_net::func_delta(std::vector<int> X) { // находим дельту для корректировки весов
	int index = X[3] + 2 * (X[2] + 2 * (X[1] + 2 * (X[0]))); // получаем индекс по элементу
	int delta = 0;
	delta = real_func[index] - func_y_net(func_net(X));
	return delta;
}

int n_net::func_E() { // Среднеквадратичная ошибка (расстояние хемминга)
	int E = 0;
	for (auto elem : all) {
		E += abs(func_delta(elem));
	}
	return E;
}

int n_net::study(std::vector<std::vector<int>> X) { // Îáó÷åíèå íåéðîííîé ñåòè
	int k = 0; // нулевая эпоха
	while ((func_E() > 0) && (k < 200)) { // эпоха обучения
		std::cout << "k = " << k << " E = " << func_E() << std::endl;
		printY();
		printV();
		std::vector<double> delta_v{ 0,0,0,0 }; // дельты весов
		double n = 0.3; // норма обучения
		for (auto elem : X) {
			delta_v[0] += n * func_delta(elem);
			for (size_t i = 0; i < C.size(); i++) {
				delta_v[i + 1] += n * func_delta(elem)*func_phi(elem, C[i]);
			}
			for (size_t i = 0; i < delta_v.size(); i++) {
				V[i] += delta_v[i];
			}
		}
		k++;
	}
	std::cout << "k = " << k << " E = " << func_E() << std::endl;
	printY();
	printV();
	return k;
}


void n_net::printY() { // выводим вектор значений БФ
	std::cout << "Y = ( ";
	for (auto elem : all) {
		std::cout << func_y_net(func_net(elem)) << " ";
	}
	std::cout << ")" << std::endl;
}

void n_net::printV() { // Выводим веса
	std::cout << "V = ( ";
	for (int i = 0; i < V.size(); i++) {
		std::cout << V[i] << " ";
	}
	std::cout << ")" << std::endl;
}
