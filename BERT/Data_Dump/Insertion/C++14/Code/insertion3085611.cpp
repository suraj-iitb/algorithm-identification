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
	int n, i, j, k, v;
	bool sorted = false;
	cin >> n;
	int a[n];
	for(i=0;i<n;i++){
		cin >> a[i];
	}

	outputArray(a, n);

	//insertion sort
	for(i=1;i<n;i++){
		v = a[i];
		j = i - 1;
		while(j>=0&&a[j]>v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;

		outputArray(a, n);
	}

}

