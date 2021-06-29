#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n;
int A[105];
int ans;
int selectSort(int A[],int n){
	int minj;
	ans=0;
	for(int i=0;i<n;i++){
		minj=i;
	    for(int j=i;j<n;j++){
	    	if(A[j]<A[minj]){
	    		minj=j;
			}
		}
	    swap(A[i],A[minj]);
	    if(i!=minj){
	    	ans++;
		}
	}
    return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
    ans=selectSort(A,n);
    for(int i=0;i<n;i++){
    	if(i>0){
    		printf(" ");
		}
		printf("%d",A[i]);
	}
	printf("\n%d\n",ans);
	return 0;
}
