#include <iostream>
#include <math.h>
#include <sstream>

using namespace std;
string bubble_sort(string str, int ary_size, int &counter);
string intArrayToString(int* ary, int ary_size);

int main()
{
	string str;
	getline(cin, str);
	int num;
	stringstream num_ss(str);
	num_ss >> num;

	getline(cin, str);
	int counter = 0;


	cout << bubble_sort(str, num, counter) << endl;
	cout << counter << endl;
	return 0;
}

string bubble_sort(string str, int ary_size, int &counter) {
	int* ary = new int[ary_size];
	stringstream ss(str);
	string buff;
	int cnt = 0;
	while (getline(ss, buff, ' ')) {
		stringstream tss(buff);
		tss >> ary[cnt];
		cnt++;
	}

	// main.
	for (int j = ary_size - 2; j >= 0; j--) {
		for (int i = 0; i <= j; i++) {
			if (ary[i + 1] < ary[i]) {
				int tmp = ary[i];
				ary[i] = ary[i + 1];
				ary[i + 1] = tmp;
				counter++;
			}
		}
	}
	return intArrayToString(ary, ary_size);
}

string intArrayToString(int* ary, int ary_size) {
	string str = "";
	for (int i = 0; i < ary_size; i++) {
		if (i == ary_size - 1) {
			str += to_string(ary[i]);
		}
		else {
			str += to_string(ary[i]) + " ";
		}
	}
	return str;
}
