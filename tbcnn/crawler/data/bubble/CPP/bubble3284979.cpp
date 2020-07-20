#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

void printarray(int a[], int n){
	for (int i=0; i<n; i++){
		if (i==n-1){
			cout << a[i] << endl;
		}
		else{
			cout << a[i] << ' ';
		}
	}

}

void insertionsort(int a[], int n){
	for (int i=0; i<n; i++){
		int v = a[i];
		int j = i-1;
		while (j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		printarray(a,n);
	}
}

int gcd(int a, int b){
	if (b==0){
		return a;
	}
	else{
		return gcd(b, a%b);
	}
}

bool prime(int n){
	if (n==2){
		return true;
	}
	else{
		int lim;
		lim = int(pow(n,0.5))+1;
		for (int i=2; i<lim; i++){
			if (n % i == 0){
				return false;
			}
		}
		return true;
	}
}

void bubblesort(int a[], int n, int& cnt){
	bool flag = true;
	while (flag){
		flag = false;
		for (int j=n-1; j>=0; j--){
			if (a[j]<a[j-1]){
				int tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
				cnt++;
				flag = true;

			}
		}
	}

}


int main(){
	int n;
	cin >> n;
	int cnt = 0;
	int a[n];
	for (int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		a[i] = tmp;
	}

	bubblesort(a,n,cnt);
	printarray(a,n);
	cout << cnt << endl;


	return 0;
}
