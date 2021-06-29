#include<iostream>
using namespace std;

int A[500005],T[500005];
int n,sum=0;

int meso(int *A,int *T,int x,int y){
	int m=x+(y-x)/2;
	int p=x,q=m+1,i=x;
	if(y-x>1){
		//i zong pleft qriht
		meso(A,T,x,m);
		meso(A,T,q,y);
	}
		while(i<=y){
		if(y!=x) sum++;
		if(q>y||(A[p]<=A[q]&&p<=m)) 
		T[i++]=A[p++];
		else 
		T[i++]=A[q++];
	}
	    for(int j=x;j<=y;j++){
	    	A[j]=T[j];
	    }
	    
}

int main(){
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	meso(A,T,1,n);
	for(int k=1;k<=n-1;k++)
	cout<<A[k]<<" ";
	cout<<A[n]<<endl;
	cout<<sum<<endl;
	return 0;
}
