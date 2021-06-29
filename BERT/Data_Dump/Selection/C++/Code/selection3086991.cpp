#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,kaisu = 0;
	cin>>a;
	int hai[a];
	for(int i = 0;i<a;i++){
		cin>>hai[i];
	}
	int zako;
	for(int i = 0;i<a-1;i++){
		int minj  =i;
		for(int j = i+1;j<a;j++){
			if(hai[minj]>hai[j]){
				minj = j;
			}

		}
		if(hai[i] != hai[minj]){
			kaisu++;
		}
		int aho;
		aho = hai[i];
		hai[i]  = hai[minj];
		hai[minj] = aho;
	}
	for(int i = 0;i<a-1;i++){
		cout<<hai[i]<<" ";
	}
	cout<<hai[a-1]<<endl;
	cout<<kaisu<<endl;
	return 0;
}

