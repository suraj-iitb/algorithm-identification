#include <iostream>

using namespace std;

void outputArray(int* arr, int& s){
	int i;
	for(i=0;i<s;i++){
		cout << arr[i];
		if(i!=s-1){cout << ' ';}
		else      {cout << endl;}
	}
}

int main(){
	int n, i, j, min_value, min_pos, value_holder, count_swipes = 0;
	cin >> n;
	int a[n];
	for(i=0;i<n;i++){cin >> a[i];}

	//selection sort
	for(i=0;i<n-1;i++){
		min_value = a[i];
		min_pos = i;

		for(j=i;j<n;j++){
			if(min_value>a[j]){
				min_value = a[j];
				min_pos = j;
			}
		}

		if(min_pos!=i){
			value_holder = a[i];
			a[i] = a[min_pos];
			a[min_pos] = value_holder;
			count_swipes++;
		}

	}
	outputArray(a, n);
	cout << count_swipes << endl;

}

