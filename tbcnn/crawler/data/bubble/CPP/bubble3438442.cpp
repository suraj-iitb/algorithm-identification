#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100;

void bubbleSort(int [], int);

void print(int [], int, int);

int main(){
	int n, a[N];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	bubbleSort(a, n);
	return 0;
}

void bubbleSort(int a[], int n){
	int count = 0;
	bool flag = true;
	while(flag){
		flag = false;
		for(int j = n-1; j > 0; j--){
			if(a[j] < a[j-1]){
				swap(a[j], a[j-1]);
				++count;
				flag = true;
			}
		}
	}
	print(a, n, count);
}

void print(int a[], int n, int count){
	cout << a[0];
	for(int i = 1; i < n; i++)
		cout << ' ' << a[i];
	cout << endl << count << endl;
}
