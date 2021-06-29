#include <iostream>
using namespace std;


void bubbleSort(int A[],int N)
{
	int count=0;
	bool flag = true;
	while(flag)
	{
		flag = false;
		for(int j=N-1;j>0;j--)
		{
			if(A[j]<A[j-1])
			{
				int swap;
				swap=A[j];
				A[j]=A[j-1];
				A[j-1]=swap;
				flag=true;
				count++;
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		if(i>0)cout<<" ";
		cout<<A[i];
	}
	cout<<endl<<count<<endl;
}

int main()
{
	int N;cin>>N;
	int A[100];for(int i=0;i<N;i++)cin>>A[i];
	bubbleSort(A,N);
	return 0;
}
