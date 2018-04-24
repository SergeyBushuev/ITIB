#include "stdafx.h"
#include "neuro.h"
#include <math.h>

n_net::n_net() {}

n_net::n_net(double w0, double w1, double w2, double w3, double w4) { // вектор весов
	W[0] = w1;
	W[1] = w2;
	W[2] = w3;
	W[3] = w4;
	W[4] = w0;
}

n_net::~n_net() {}

void n_net::get_real_func() {					
	double interval = (2.0 + 2.0) / (20.0 + 2.0); // определение интервала
												 
	for (int i = 0; i < 40; i++) {
		real_func.push_back(exp((-2.0 + interval * i) - 1.0)); // подсчет реальных значений функции
	}
	neur_func.push_back(real_func[0]);
	neur_func.push_back(real_func[1]);
	neur_func.push_back(real_func[2]);
	neur_func.push_back(real_func[3]);
}


double n_net::func_delta(double real, double neur) { // Ошибка прогноза
	double delta = real - neur;
	return delta;
}

double n_net::func_E() { // суммарная среднеквадратичная ошибка
	double E = 0;
	for (int i = 0; i < neur_func.size(); i++) {
		double delta = func_delta(real_func[i], neur_func[i]);
		E += delta * delta;
	}
	E = sqrt(E);
	return E;
}

double n_net::study(int max) { // обучение нейронной сети
	int k = 0;
	double n = 0.66;
	while (((func_E() > 0.001) || (k == 0)) && (k < max)) {							 // эпоха обучения
		std::cout << "k = " << k << std::endl << "E = " << func_E() << std::endl;
		printW();
		for (int i = 4; i < 20; i++) {										 // Öèêë ïî îáó÷àþùåé âûáîðêå
			if (neur_func.size() < i + 1) {
				neur_func.push_back(0);
			}
			neur_func[i] = W[4];
			for (int j = 0; j < 4; j++) {									// подсчет функции на данном этапе обучения 
				neur_func[i] += W[j] * neur_func[i - 4 + j];
			}
			for (int j = 0; j < 4; j++) {									 // пересчет весов после каждого шага
				W[j] += n * func_delta(real_func[i], neur_func[i])*neur_func[i - 4 + j];
			}
			W[4] += n * func_delta(real_func[i], neur_func[i]);
			k++;
		}
	}
	std::cout << "k = " << k << std::endl << "E = " << func_E() << std::endl;
	printW();
	return k;
}

void n_net::work() { // Моделирование весов, полученных в ходе обучения 
	for (int i = 20; i < 40; i++) {
		if (neur_func.size() < i + 1) {
			neur_func.push_back(0);
		}
		neur_func[i] = 0;
		for (int j = 0; j < 4; j++) {
			neur_func[i] += W[j] * neur_func[i - 4 + j];
		}
		neur_func[i] += W[4];
	}
	std::cout << std::endl << "real               neur" << std::endl;
	for (int i = 0; i < 40; i++) {
		std::cout << real_func[i] << "        " << neur_func[i] << std::endl;
	}
}

void n_net::printW() { // вывод весов
	std::cout << "W = ( " << W[4] << " ";
	for (int i = 1; i < 5; i++) {
		std::cout << W[i] << " ";
	}
	std::cout << ")" << std::endl;
}
