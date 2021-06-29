#include<iostream>
using namespace std;
int main(){
	int n;
	int v;
	int i,j;
	int s,d;
	int A[1000]={0};
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>A[i];
	}
	for(i=1;i<=n;i++){
		v=A[i];
		j=i-1;
		while(j>=0&&A[j]>v){
			A[j+1]=A[j];
			j--;
			A[j+1]=v;
		}
		for(s=1;s<=n;s++){
			cout<<A[s];
			if(s<n){
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
