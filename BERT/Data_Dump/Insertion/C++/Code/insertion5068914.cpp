#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int N,t;
	cin>>N;
	int a[N+1]={-0x7fffffff};
	for(int i=1;i<=N;i++)cin>>a[i];
	for(int i=1;i<=N;i++)
	{
		int j=i;
		while(a[j]<a[j-1]){
			t=a[j],a[j]=a[j-1],a[j-1]=t;
			j--;
		}
		for(j=1;j<N;j++)
			cout<<a[j]<<' ';
		cout<<a[N]<<endl;
	}
	return 0;
}
