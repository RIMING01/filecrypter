#pragma once
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
vector<int> get_snums() {
	vector<int> vec;
	fstream f("D:\\galaxy\\snum.txt", fstream::in);
	if (!f) {
		f.close();
		f.clear();
		f.open("D:\\galaxy\\snum.txt");
		vector<int> snums;
		bool jump = false;
		int si;
		for (int i = 0; snums.size() < 10001; i++) {
			si = sqrt(i) + 1;
			for (int j = 1; j < si; j++) {
				if (i % j == 0 && i != j) {
					jump = true;
					break;
				}
			}
			if (jump) {
				jump = false;
				continue;
			}
			else {
			snums.push_back(i);
			}
		}
		for (auto num : snums) {
			f << num << " ";
		}
		return snums;
	}
	int num;
	while (f >> num) {
		vec.push_back(num);
	}
	return vec;
}

int get_p() {
	srand(time(0));
	vector<int> snums(get_snums()),rets;
	for (int i = 0; i < snums.size(); i++) {
		if (i % 2 == 0) {
			rets.push_back(snums[i]);
		}
	}
	return rets[rand()];
}
int get_q() {
	srand(time(0));
	vector<int> snums(get_snums()), rets;
	for (int i = 0; i < snums.size(); i++) {
		if (i % 2) {
			rets.push_back(snums[i]);
		}
	}
	return rets[rand()];
}