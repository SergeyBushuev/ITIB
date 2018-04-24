#include "stdafx.h"
#include "neuro.h"
#include <string>
#include <vector>
#include <iostream>



int main(int argc, char *argv[]) {
	if (argc == 2) {
		int n = atoi(argv[1]);
		if (n <= 0) n = 2000;
		n_net neur;
		neur.get_real_func();
		neur.study(n);
		neur.work();
	}
	else {
		n_net neur;
		neur.get_real_func();
		neur.study(2000);
		neur.work();
	}

	int pause;
	std::cin >> pause;
	return 0;
}
