#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt;//记录交换次数 
void print(int A[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<A[i]<<(i==n-1?"\n":" ");
	}
}
void selectsort(int A[],int n){
	int i,j,minj;
	for(i=0;i<n-1;i++){
		minj=i;
		for(j=i+1;j<n;j++){
			if(A[j]<A[minj])minj=j;
		}
		if(i!=minj){
		  swap(A[i],A[minj]);
		  cnt++;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	selectsort(A,n);
	print(A,n);
	cout<<cnt<<endl;
   return 0;
}

