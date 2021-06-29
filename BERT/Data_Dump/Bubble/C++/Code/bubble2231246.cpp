#include<algorithm>
#include<stdio.h>
#include<iostream>
using namespace std;
static const int MAX = 200000;
int main(){
	int R[MAX], n;
	cin>> n;
	for (int i = 0; i < n; i++){
		cin >> R[i];
	}
	int k = 0;
	bool flag = 1;
	for (int i = 0; flag; i++){
		flag = 0;
		for (int j = n - 1; j > i; j--){
			if (R[j - 1] > R[j]){
				swap(R[j - 1], R[j]);
				k++;
				flag = 1;
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (i != 0)
			printf(" ");
		printf("%d", R[i]);
	}
	printf("\n%d\n", k);
	return 0;
}
