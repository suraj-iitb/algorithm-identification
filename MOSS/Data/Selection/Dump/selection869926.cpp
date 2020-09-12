#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

#define N_MAX 105

using namespace std;

int main(void){

	int N;
	int arry[N_MAX];
	int min_i;
	int cnt=0;

	cin>>N;

	for(int i=0;i<N;i++){
		cin>>arry[i];
	}

	for(int i=0;i<N;i++){
		min_i=i;
		for(int j=i;j<N;j++){
			if(arry[j]<arry[min_i]){
				min_i=j;
			}
		}
		if(min_i!=i){
			swap(arry[i],arry[min_i]);
			cnt++;
		}
	}

	for(int i=0;i<N-1;i++){
		cout<<arry[i]<<" ";
	}
	cout<<arry[N-1]<<endl;
	cout<<cnt<<endl;

	return 0;
}
