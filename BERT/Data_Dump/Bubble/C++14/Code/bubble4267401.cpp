#include<iostream>
using namespace std;
int bubbleSort(int A[],int N){
bool flag=true;
	int j,node,ans=0;
	while(flag){
	flag=false;
		for(j=N-1;j>0;j--){
			if(A[j]<A[j-1]){
			node=A[j];
				A[j]=A[j-1];
				A[j-1]=node;
				ans++;
				flag=true;
			}
			
		}
	}
	return ans;
}

main(){
	int n,i,ans;
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);
	ans=bubbleSort(A,n);
	for(i=0;i<n;i++){
	    if(i==n-1){
	printf("%d",A[i]);
	        break;
	    }
	printf("%d ",A[i]);}
	printf("\n%d\n",ans);
	return 0;
}
