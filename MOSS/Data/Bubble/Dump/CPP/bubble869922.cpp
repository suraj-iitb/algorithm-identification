#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

#define N_MAX 105

using namespace std;

int main(void){

	int N;
	int arry[N_MAX];
	int cnt=0;

	cin>>N;

	for(int i=0;i<N;i++){
		cin>>arry[i];
	}

	for(int i=0;i<N-1;i++){
		for(int j=N-1;j>i;j--){
			if(arry[j]<arry[j-1]){
				swap(arry[j],arry[j-1]);
				cnt++;
			}
		}
	}

	for(int i=0;i<N-1;i++){
		cout<<arry[i]<<" ";
	}
	cout<<arry[N-1]<<endl;
	cout<<cnt<<endl;

	return 0;
}
