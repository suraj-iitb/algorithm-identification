#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

void printArray(int *a,int n);

void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int *a,int n,int &count){
	bool flag = true; // reverse neighber exists
	while(flag == true){
		flag = false;
		for(int j = n - 1; j > 0; j--){
			if( a[j] < a[j-1]){
				swap(a[j],a[j-1]);
				count++;
				flag = true;
			}
		}
	}
}

void selectionSort(int *a,int n,int &count){
	for(int i = 0; i < n; i++){
		int minj = i;
		for(int j = i; j < n; j++){
			if(a[j] < a[minj]){
				minj = j;
			}
		}
		if( i != minj){
			swap(a[i],a[minj]);
			count++;
			//printArray(a,n);
		}
	}
}

void printArray(int *a,int n){
	cout<<a[0];
	if( n > 1){
		for(int i = 1; i < n; i ++){
			cout <<" "<<a[i];
		}
	}
	cout<<endl;
}


int main()
{
	int n;
	cin >> n ;
	int *targetArray = new int[n];
	for(int i = 0 ; i < n; i++) cin >> targetArray[i];
	int count = 0;
	selectionSort(targetArray,n,count);
	printArray(targetArray,n);
	cout<< count<<endl;
	delete[] targetArray;
	return 0;
}



