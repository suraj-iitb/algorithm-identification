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
	int n,i,j;
	memset(a,0,sizeof(a));
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		for(j=n-1;j>i;j--){
			if(a[j]<a[j-1])
				swap(j,j-1);
		}
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
