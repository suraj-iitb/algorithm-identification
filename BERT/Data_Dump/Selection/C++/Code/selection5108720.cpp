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

void Selection_Sort(int A[],int N)
{
	int i, j, minj, m;
	for(i=0;i<N;i++)
	{
		minj=i;
		for(j=i+1;j<N;j++)
		{
			if(A[j]<A[minj]) minj=j;
		}
		m=A[minj];
		A[minj]=A[i];
		A[i]=m;
		if(i!=minj) T+=1;	
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
	Selection_Sort(A,n);
	print(A,n);
	cout<<T<<endl;
	return 0;
 }
