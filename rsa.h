#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct de {
	de() { d = 0; e = 0; length = 0; }
	de(int d, int e, int length) :d(d), e(e), length(length) {}
	bool operator==(de l) {
		return l.d == d && l.e == e && l.length == length;
	}
	int d;
	int e;
	int length;
};

int pow(int l, int r) {
	for (int i = 1; i < r; i++) {
		l *= l;
	}
	return l;
}

fstream& operator>>(fstream& f, de& d) {
	f >> d.d;
	f >> d.e;
	f >> d.length;
	return f;
}

fstream& operator<<(fstream& f, de& d) {
	f << d.d << " ";
	f << d.e << " ";
	f << d.length;
	return f;
}

class Rsa {
public:
	Rsa(int p, int q) :p(p), q(q), n(p* q), m((p - 1)* (q - 1)) {
		for (int i = 1; i < sqrt(m); i++) {
			if (m % i == 0&&m!=i) {
				mys.push_back(i);
			}
		}
		bool jump = false;
		srand(time(0));
		for (int i = lengths[0]; i < lengths.size(); i++) {
			for (int j = pow(10, (i - 1)); j < pow(10, i); j++) {
				for (auto my : mys) {
					if (j % my == 0) {
						jump = true;
						break;
					}
				}
				if (jump) {
					jump = false;
					continue;
				}
				else {
					for (int k = 0;; k++) {
						if (k * j % m == 1) {
							des[i].push_back(de(j, k, i));
							break;
						}
					}
				}
			}
		}
	}
	
	de malloc_pwd(int length) {
	yan:
		int ui = rand();

		if (length < lengths[lengths.size()-1]+1) {
			de ret = this->des[length][ui % des[length].size()];
			for (int i = 0; i < udes[length].size(); i++) {
				if (ret == udes[length][i]) {
					if (udes[length].size() != des[length].size()) {
						goto yan;
					}
					else {

					}
				}
			}
			udes[length].push_back(ret);
			return ret;
		}
		else {
			throw runtime_error("length_error!");
		}
	}
	
	bool delete_pwd(de pwd) {

		for (int i = 0; i < udes[pwd.length].size(); ++i) {
			if (udes[pwd.length][i] == pwd) {
				udes[pwd.length].erase(udes[pwd.length].begin() + i);
				return true;
			}
		}
		return false;
	}

	
	int encrypt(int pub, int msg) const{
		return pow(msg, pub) % n;
	}
	
	
	int decrypt(int pri, int msg) const{		
		return pow(msg, pri) % n;
	}
	
private:
	const int p, q, n, m;
	vector<int> mys;
	map<int, vector<de>> des, udes;
	vector<int> lengths = { 2,3,4 };
};
