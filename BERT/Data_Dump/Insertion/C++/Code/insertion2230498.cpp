#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
static const int MAX = 200000;
int main(){
	int R[MAX], n;
	cin >> n;
	int j;
	for (int i = 0; i < n; i++)
		cin >> R[i];
	int key;
	for (int i = 0; i < n; i++){
                key=R[i];
		j = i - 1;
		while (j >= 0 && R[j] > key){
			R[j + 1] = R[j];
			j--;
		}
		R[j + 1] = key;
		for (int i = 0; i < n; i++){
                        if(i>0)
                          printf(" ");
			printf("%d", R[i]);
		}
		printf("\n");
	}
	return 0;
}
