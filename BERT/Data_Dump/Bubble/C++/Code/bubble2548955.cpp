#include <iostream>
#include <algorithm>
using namespace std;

int bubbleSort(int A[],int N){
	int iii=0;
	int flag=1;
	int ans1=0;
	while(flag){
		flag=0;
		for(int j=N-1;j>0;j--){
			if(A[j]<A[j-1]){
				swap(A[j-1],A[j]);
				flag=1;
				//cout<<"test"<<endl;
				ans1++;
			}
		}
		//iii++;
		}
	return ans1;
}
int main(){
	ios::sync_with_stdio(false);
	int N,A[100],ans=0;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	ans=bubbleSort(A,N);
	for(int ji=0;ji<N;ji++){
		if(ji==N-1){cout<<A[ji]<<endl;}
		else{cout<<A[ji]<<" ";
		}
	}
	cout<<ans<<endl;
	int aa;cin>>aa;
	return 0;
}
