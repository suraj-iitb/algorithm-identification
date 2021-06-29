#include<algorithm>
#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	int R[100],n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> R[i];
	}
	int min;
	int swap = 0;
        int tmp;
	for (int i = 0; i < n; i++){
		min = i;
		for (int j = i; j < n; j++){
			if (R[j] < R[min])
				min = j;
		}
		if (i != min){
                        tmp=R[i];
                        R[i]=R[min];
                        R[min]=tmp;
			swap++;
		}
	}
	for (int i = 0; i < n; i++){
		if (i != 0)
			cout << " ";
		cout << R[i];
	}
	cout << endl;
	cout << swap << endl;

}
