#include <bits/stdc++.h>
using namespace std;
#define max_num_value 100

int bubble_sort(vector<int> &value, int num_value){
	int i, j, num_switch=0;
	bool flag_sorted=0;
	
	for(i=0; !flag_sorted; i++){
		flag_sorted = 1;
		for(j=num_value-1; j>=i+1; j--){
			// j-1要素がj要素より大きい場合，要素をスワップして
			// ソート完了フラグをfalseにする
			// 交換数も更新する
			if(value.at(j-1)>value.at(j)){
				swap(value.at(j-1), value.at(j));
				flag_sorted = 0;
				num_switch++;
			}
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
	
	// バブルソート
	num_switch = bubble_sort(value, num_value);
	
	// 出力
	for(i=0;i<num_value-1;i++){
		cout << value.at(i) << " ";
	}
	cout << value.at(num_value-1) << endl << num_switch << endl;
		
	return 0;
}
