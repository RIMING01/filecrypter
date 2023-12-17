#pragma once
#include "rsa.h"
#include <string>
#include <fstream>
bool encryptfile(string fn, Rsa rsa, de d, int p, int q) {
	fstream f(fn.c_str(), fstream::binary | fstream::in);
	if (!f) {
		return false;
	}
	int fc=0b0;
	f >> fc;
	int msg = rsa.encrypt<int>(d.d, fc);
	f.close();
	fstream fo((fn+".rsa").c_str(), fstream::binary | fstream::out);
	fo << d << " " << p << " " << q << " " << msg;
	fo.close();
	return true;
}

bool decryptfile(string fn,string tuo) {
	fstream f(fn.c_str(), fstream::binary | fstream::in);
	if (!f) {
		return false;
	}
	int fc = 0b0;
	de d;
	int p, q;
	f >>d>>p>>q>> fc;
	Rsa rsa(p, q);
	int msg = rsa.encrypt<int>(d.d, fc);
	f.close();
	fstream fo((fn + "."+tuo).c_str(), fstream::binary | fstream::out);
	fo << msg;
	fo.close();
	return true;
}
