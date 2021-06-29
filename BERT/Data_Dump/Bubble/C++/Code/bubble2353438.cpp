/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: baisganon
 *
 * Created on 2017/06/04, 19:09
 */

#include<iostream>
using namespace std;

int count = 0;

void bubbleSort(int A[],int n){
	bool flag = true;
	while(flag){
		flag = 0;
		for(int j=n-1;j>0;j--){
			if(A[j]<A[j-1]){
				int tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
				flag = 1;
				count++;
			}
		}
	}
	return;
}

int main(){
	int size;
	cin >> size;
	int S[size];
	for(int i=0;i<size;i++){
		cin >> S[i];
	}

	bubbleSort(S,size);

	for(int i=0;i<size;i++){
		cout<<S[i]<<((i==size-1)?"":" ");
	}
	cout << endl << count << endl;
        int xxx;
        cin >> xxx;
	return 0; 
}
