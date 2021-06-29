#include <iostream>
using namespace std;

int main() {

	int arr_num = 0;
	int* p_arr = NULL;
	int sort_data = 0xffffffff;
	int sort_pos = 0;
	int sort_count = 0;

	cin >> arr_num;

	p_arr = new int[arr_num];

	// input
	for (int i = 0; i < arr_num; i++) {
		cin >> p_arr[i];
	}

	for (int i = 0; i < arr_num; i++) {
		int first_sort_pos = i;
		sort_pos = i;
		sort_data = p_arr[i];

		for (int j = i + 1; j < arr_num; j++) {
			int tmp = p_arr[j];

			if (tmp < sort_data) {
				sort_data = tmp;
				sort_pos = j;
			}
		}

		if (first_sort_pos != sort_pos) {
			// 未ソート位置の先頭にソートする
			int tmp = p_arr[sort_pos];
			p_arr[sort_pos] = p_arr[i];
			p_arr[i] = tmp;

			sort_count++;
		}
	}

	for (int i = 0; i < arr_num - 1; i++) {
		cout << p_arr[i] << " ";
	}

	cout << p_arr[arr_num - 1] << endl;
	cout << sort_count << endl;
}
