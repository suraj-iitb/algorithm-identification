#include<iostream>
using namespace std;

void print(int A[], int N)
{
	int k;
	for(k=0;k<N;k++)
    {
    	if(k>0) cout<<" ";
        cout<<A[k];
    }
    cout<<endl;
}

void insertionSort(int A[],int N)
{
	int i, v, j, k;
	for(i=1;i<N;i++)
	{
		v=A[i];
		j=i-1;
		while(j>=0&&A[j]>v)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
	    print(A,N);
	}
 } 
 
 int main()
 {
    int n, i, k;
    cin>>n;
    int A[100];
    for(i=0;i<n;i++)
    {
    	cin>>A[i];
	}
	print(A,n);
	insertionSort(A,n);
	return 0;
 }
