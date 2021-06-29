/////////////////////    答案    /////////////// 
/*
注意点：
1. 
*/
//----------------------自打1------------------ 

#include<iostream>
using namespace std;
int c[10010],a[2000005],b[2000005];
int main(){
	int n,k=10010;
	cin>>n;
	for(int i=0;i<k;++i){
		c[i]=0;
	}
	for(int i=0;i<n;++i){
		cin>>a[i];
		c[a[i]]++;
	}
	for(int i=0;i<k;++i){
		c[i]+=c[i-1];
	}
	for(int i=n-1;i>=0;--i){				//1.for n-1 to 0 保证了稳定性 
		b[c[a[i]]]=a[i];
		c[a[i]]--;
	}
	for(int i=1;i<=n;++i){
		cout<<b[i]<<" \n"[i==n];
	}
	return 0;
}
