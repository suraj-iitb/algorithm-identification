#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <string>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cstdlib>
using namespace std;

void trace(int A[],int N){
	for(int i=0;i<N;i++){
		if(i>0)cout << ' ';
		cout << A[i];
	}
	cout << endl;
}

void selectionSort(int A[],int N){
	
	int minj,count=0;
	for(int i=0;i<N;i++){
		minj = i;
		for(int j=i;j<N;j++){
			if(A[j]<A[minj]){
				minj= j;
			}
		}
		swap(A[i],A[minj]);
		if(i!=minj)count++;
	}
	trace(A,N);
	cout << count;
	cout << endl;
}

int main(){

	int N;
	int A[100];

	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	selectionSort(A,N);

	return 0;
}
