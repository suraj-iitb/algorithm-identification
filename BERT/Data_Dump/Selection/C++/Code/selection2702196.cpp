#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
int a[100],count=0;
void swap(int x,int y){
	int tmp;
	tmp=a[y];
	a[y]=a[x];
	a[x]=tmp;
	count++;
}
int main(int argc, char *argv[]) {
	int n,i,j,min;
	memset(a,0,sizeof(a));
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[min])
				min=j;
		}
		if(i!=min)
			swap(i,min);
	}
	for(i=0;i<n;i++){
		if(i!=n-1)
			cout<<a[i]<<" ";
		else
			cout<<a[i]<<endl;
	}
	cout<<count<<endl;
	return 0;
}
