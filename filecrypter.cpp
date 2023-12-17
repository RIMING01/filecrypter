// filecrypter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "filersacrypt.h"
#include "snum.h"
#include <iostream>
#include <windows.h>
using namespace std;
int main(int argc, char** argv) {
	if (argc == 2 && argv[0] == "en") {
		int p = get_p(), q = get_q();
		cout << "正在加密中......" << endl;
		Rsa rsa(p, q);
		de d(rsa.malloc_pwd(4));
		bool flag = encryptfile(string(argv[1]), rsa, d, p, q);
		if (flag) {
			cout << "成功将文件" << argv[1] << "加密保存至" << string(argv[1]) + ".rsa" << endl;
			system("pause");
			return 0;
		}
		else {
			cout << "加密失败！" << endl;
			system("pause");
			return -1;
		}
	}
	else if (argc == 3 && (argv[0] == "de")) {
		cout << "正在解密中......" << endl;
		bool flag = decryptfile(string(argv[1]),string(argv[2]));
		if (flag) {
			cout << "成功将文件" << argv[1] << "解密保存至" << string(argv[1]) + "." + argv[2] << endl;
			system("pause");
			return 0;
		}
		else {
			cout << "解密失败！" << endl;
			system("pause");
			return -1;
		}
	}
	else if (argc == 0) {
		cout << "欢迎使用RSA文件加密工具" << endl << endl;
		int cmd;
	here:
		cout << "请选择执行的操作：1.加密 2.解密" << endl;
		cin >> cmd;
		if (cmd > 2 || cmd < 1) {
			cout << "命令错误！" << endl;
			return -1;
		}
		string fn, tuo;
		cout << "请输入文件名：" << endl;
		cin >> fn;
		if (cmd == 1) {
			int p = get_p(), q = get_q();
			cout << "正在加密中......" << endl;
			Rsa rsa(p, q);
			de d(rsa.malloc_pwd(4));
			bool flag = encryptfile(fn, rsa, d, p, q);
			if (flag) {
				cout << "成功将文件" << fn << "加密保存至" << fn + ".rsa" << endl;
				system("pause");
				return 0;
			}
			else {
				cout << "加密失败！" << endl;
				system("pause");
				return -1;
			}
		}
		else if (cmd == 2) {
			cout << "请输入解密后的拓展名(不加 . ,如docx)：" << endl;
			cin >> tuo;
			cout << "正在解密中......" << endl;
			bool flag = decryptfile(fn, tuo);
			if (flag) {
				cout << "成功将文件" << argv[1] << "解密保存至" << fn + "." + tuo << endl;
				system("pause");
				return 0;
			}
			else {
				cout << "解密失败！" << endl;
				system("pause");
				return -1;
			}
		}
	}
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
