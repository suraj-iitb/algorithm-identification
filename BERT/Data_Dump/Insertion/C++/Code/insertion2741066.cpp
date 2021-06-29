#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 100;
int n;
int arr[MAXN];

void output();

void insertion_sort() {
	for(int i = 1; i < n; i++) {
		int k = arr[i];
		int j = i - 1;
		while( j >= 0 && arr[j] > k){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = k;
		output();
	}
} 

void input() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
}

void output() {
	printf("%d",arr[0]);
	for(int i = 1; i < n; i++) {
		printf(" %d", arr[i]);
	}
	puts(""); 
}

int main() {
	input();
	output();
	insertion_sort(); 
	return 0;
}
