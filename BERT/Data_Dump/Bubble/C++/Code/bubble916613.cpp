#include <iostream>
using namespace std;

/*
BubbleSort(A)
1 for i = 0 to A.length-1
2     for j = A.length-1 downto i+1
3         if A[j] < A[j-1]
4             swap A[j] and A[j-1]
*/

int BubblueSort(int dat[],int n){
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(dat[j]<dat[j-1]){
                int tmp=dat[j];
				dat[j]=dat[j-1];
                dat[j-1]=tmp;
				cnt++;
			}
		}
	}
	for(int i=0;i<n-1;i++)
	      cout<<dat[i]<<" ";
	cout<<dat[n-1]<<endl;
	cout<<cnt<<endl;
}

int main(){
	int n;
	int dat[100];
	cin>>n;
	for(int i=0;i<n;i++)
	      cin>>dat[i];

	 
	 BubblueSort(dat,n);
	
	
	return 0;
}
