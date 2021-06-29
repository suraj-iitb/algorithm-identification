#include <bits/stdc++.h>
using namespace std;
#define max_num_value 100

int selection_sort(vector<int> &value, int num_value){
	int i, j, j_min, num_switch=0;
	
	for(i=0;i<num_value;i++){
		// 未ソート部の位置を記録
		j_min = i;
		for(j=i+1; j<num_value; j++){
			if(value.at(j)<value.at(j_min)){
				j_min = j;
			}
		}
		
		// 未ソート部先頭要素と最小値をスワップ
		// 反転数を更新
		if(i!=j_min){
			swap(value.at(i), value.at(j_min));
			num_switch++;
		}
	}
	return num_switch;
}

int main(){
	int num_value, i, num_switch;
	vector <int> value(max_num_value);
	cin >> num_value;
	for(i=0;i<num_value;i++){
		cin >> value.at(i);
	}
	
	// 選択ソート
	num_switch = selection_sort(value, num_value);
	
	// 出力
	for(i=0;i<num_value-1;i++){
		cout << value.at(i) << " ";
	}
	cout << value.at(num_value-1) << endl << num_switch << endl;
		
	return 0;
}
