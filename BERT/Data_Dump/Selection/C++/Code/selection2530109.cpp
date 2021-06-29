#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
	int n,a[100],i,count=0,minj=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		minj=i;
		for(int j=i;j<n;j++){
			if(a[j]<a[minj]){
				minj=j;
			}
		}
		if(i!=minj){
			swap(a[i],a[minj]);
			count++;
		}
	}
	for(i=0;i<n;i++){
		if(i==n-1)cout<<a[i]<<endl;
		else cout<<a[i]<<" ";
	}
	cout<<count<<endl;
	return 0;
}
