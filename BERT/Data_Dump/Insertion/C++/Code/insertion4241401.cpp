#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int syc(long i,long Min,long Max){
	if(Min <= i && i <= Max){
		return 1;
	}else{
		exit(1);
		//return 0;
	}
}

int main(){
	
	int x;
	cin >> x;
	syc(x,1,100);
	int a[x];
	int temp;
	
	for(int i=0;i<x;i++){
		cin >> a[i];
		syc(a[i],0,1000);
	}
	
	for(int i=1;i<x;i++){
		for(int p=0;p<x;p++){
			cout << a[p];
			if(p<x-1)cout << " ";
		}
		cout << endl;
		for(int j=0;j<i;j++){
			if(a[j]>a[i]){
				temp=a[i];
				for(int k=i;k>j;k--){
					a[k]=a[k-1];
				}
				a[j]=temp;
			}
		}
	}
	for(int p=0;p<x;p++){
			cout << a[p];
			if(p<x-1)cout << " ";
	}
	cout << endl;
	
	return 0;
}

