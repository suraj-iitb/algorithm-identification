#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;

string intArrayToString(int* ary, int ary_size);
void insert_sort(string ary, int ary_size);

int main()
{
	string str;
	getline(cin, str);
	stringstream ss_size(str);
	int ary_size;
	ss_size >> ary_size;

	getline(cin, str);
        cout << str << endl;

	insert_sort(str, ary_size);

    return 0;
}

void insert_sort(string ary, int ary_size) {
	// pram div into int array
	stringstream ss(ary);
	string buff;
	int* tar_ary = new int[ary_size];
	int cnt = 0;

	while (getline(ss, buff, ' ')) {
		stringstream num_ss(buff);
		num_ss >> tar_ary[cnt];
		cnt++;
	}

	for (int i = 1; i < ary_size; i++) {
		int v = tar_ary[i];
		int cnt = 0;
		for (int j = i - 1; j >= 0 && tar_ary[j] > v; j--) {			
			tar_ary[j + 1] = tar_ary[j];
			cnt = j;
			tar_ary[cnt] = v;
		}
		cout << intArrayToString(tar_ary, ary_size) << endl;
	}
	delete(tar_ary);

	return;
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
