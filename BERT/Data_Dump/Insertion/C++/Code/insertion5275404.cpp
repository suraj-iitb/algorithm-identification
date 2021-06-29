#include <iostream>
using namespace std;

void output_arr_status(int*, int);

int main() {

	int element_num = 0;
	int* p_arr_num = NULL;
	int sort_pos = 0;

	// 数列の長さを入力
	cin >> element_num;
	p_arr_num = new int[element_num];

	for (int i = 0; i < element_num; i++) {
		// 整数値を入力
		cin >> p_arr_num[i];
	}

	for (int i = 1; i < element_num; i++) {
		
		// 配列の状態を表示する
		output_arr_status(p_arr_num, element_num);

		sort_pos = i;
		int sort_data = p_arr_num[i];

		// 挿入位置を検索する
		for (int find_pos = i; find_pos > 0; find_pos--) {

			// 配列を後ろから検索し、挿入位置に挿入する
			if (sort_data < p_arr_num[find_pos - 1]) {
				sort_pos = find_pos - 1;
				p_arr_num[find_pos] = p_arr_num[find_pos - 1];
			}		
		}

		p_arr_num[sort_pos] = sort_data;
	}
	
	output_arr_status(p_arr_num, element_num);
}

void output_arr_status(int* p_arr, int arr_size) {

	for (int i = 0; i < arr_size; i++) {
		if (i == arr_size - 1) {
			cout << p_arr[i] << endl;
		}
		else {
			cout << p_arr[i] << " ";
		}
	}
}
