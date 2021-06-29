#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100;

void selectionSort(int [], int);

void print(int [], int, int);

int main(){
	int n, a[N];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	selectionSort(a, n);
	return 0;
}

void selectionSort(int a[], int n){
	int minJ, num = 0;
	for(int i = 0; i < n; i++){
		minJ = i;
		for(int j = i+1; j < n; j++){
			if(a[j] < a[minJ])
				minJ = j;
		}
		if(minJ != i){
			swap(a[i], a[minJ]);
			num++;
		}
	}
	print(a, n, num);
}

void print(int a[], int n, int num){
	cout << a[0];
	for(int i = 1; i < n; i++)
		cout << ' ' << a[i];
	cout << endl << num << endl;
}
