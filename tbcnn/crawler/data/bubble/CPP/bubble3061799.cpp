#include<iostream>
using namespace std;

//使用flag的冒泡排序法
int bubbleSort(int arr[],int N){
	int sw = 0;//记录次数 
	bool flag = 1;
	for( int i = 0; flag ; i++){
		flag = 0;
		for(int j = N - 1; j >= i + 1; j--){
			if(arr[j] < arr[j - 1]){
				swap(arr[j], arr[j - 1]);
				flag = 1;
				sw++;
			}
		}
	}
	return sw; 
} 
int main(){
	int arr[100], N, sw;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	sw = bubbleSort(arr, N);
	for(int i = 0; i < N; i++){
		if(i) cout << " ";
		cout << arr[i];
	}
	cout << endl;
	cout << sw << endl;
	return 0;
}
