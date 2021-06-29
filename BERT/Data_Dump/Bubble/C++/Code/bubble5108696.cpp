#include<iostream>
using namespace std;
int T=0;

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

void Bubble_Sort(int A[],int N)
{
	int flag=1;
	int i, j;
	while(flag)
	{
		flag=0;
		for(j=N-1;j>0;j--)
		{
			if(A[j]<A[j-1])
			{
				i=A[j];
				A[j]=A[j-1];
				A[j-1]=i;
				T+=1;
				flag=1;
			}
		}
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
	Bubble_Sort(A,n);
	print(A,n);
	cout<<T<<endl;
	return 0;
 }
