#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int n,a[100];
void syuturyoku(){
	for(int i=0;i<n;i++){
		if(i==n-1)cout<<a[i]<<endl;
		else cout<<a[i]<<" ";
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	syuturyoku();
	for(int i=1;i<n;i++){
		int v=a[i];
		int j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
			a[j+1]=v;
		}
		syuturyoku();
	}
	return 0;
}
