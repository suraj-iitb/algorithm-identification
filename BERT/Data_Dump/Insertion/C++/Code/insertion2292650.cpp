//3_2(1_1_A) ?????\?????????
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int printArray(int data[],int num){
	int i;
	for(i=0;i<num;i++){
		if(i!=0)printf(" ");
		printf("%d",data[i]);
	}
	printf("\n");
	return 0;
}

int main(){
	int data[100],n;
	int j,v;
	
	cin >> n;
	for(int i=0;i<n;i++)cin >> data[i];
	
	for(int i=0;i<n;i++){
		v=data[i];
		j=i-1;
		while(j>=0 && data[j]>v){
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=v;
		printArray(data,n);
	}

	
	return 0;
}
