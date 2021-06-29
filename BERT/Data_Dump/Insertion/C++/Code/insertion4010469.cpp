#include <iostream>
using namespace std;
void trace(int A[],int N)
{
	int i;
	cout<<A[0];
	for(i=1;i<N;i++)cout<<' '<<A[i];
	cout<<endl; 
}

void insertionSort(int A[],int N)
{
	int i,j,v;
	for(i=1;i<N;i++){
		v=A[i];
		j=i-1;
		while(j>=0&&v<A[j]){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
	    trace(A,N);
	}

}
int main() {
	
	int i,N;
	int A[100];
		cin >>N;
	for(i=0;i<N;i++)cin>>A[i];
	void trace(int A[],int N);
	void insertionSort(int A[],int N);
    trace(A,N);
	insertionSort(A,N);
	return 0;
}
