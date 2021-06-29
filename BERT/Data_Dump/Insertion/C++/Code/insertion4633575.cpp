#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 200005
#define _rep(i, a, n) for(int i = a; i < n; i++)
#define rep(i, a, n) for(i = a; i < n; i++)

int a[maxn];
int n, i;
void trace(int a[], int n){
	rep(i, 0, n){
		if(i)	cout << ' ';
		cout << a[i];
	}
	cout <<endl;
}
void insertionSort(int a[], int n){
	int i ,j, v;
	rep(i, 1, n){
		v = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > v){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		trace(a, n);
	}
} 
int main(void){
	cin >> n;
	_rep(i, 0, n)	cin >> a[i];
	trace(a, n);
	insertionSort(a, n);
	return 0;
} 
