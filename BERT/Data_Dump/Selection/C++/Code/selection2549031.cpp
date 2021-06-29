#include <iostream>
#include <algorithm>
using namespace std;

int selectionSort(int A[],int N){
	int minj=0,i,j,ans1=0,tmp=0;
	for(i=0;i<N;i++){
		minj=i;
		for(j=i;j<N;j++){
			if(A[j]<A[minj]){
				minj=j;
			}
		}
		if(i!=minj){
		tmp=A[i];A[i]=A[minj];
		A[minj]=tmp;
		ans1++;
		}
	}
	return ans1;
}

int main(){
	ios::sync_with_stdio(false);
	int A[100]={0},N,ans=0;
	cin>>N;
	for(int ii=0;ii<N;ii++){
		cin>>A[ii];
	}
	ans=selectionSort(A,N);
	for(int ii=0;ii<N;ii++){
		if(ii!=N-1){cout<<A[ii]<<" ";
		}
		else {cout<<A[ii]<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
