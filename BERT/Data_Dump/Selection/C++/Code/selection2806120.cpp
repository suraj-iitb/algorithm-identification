#include <iostream>
using namespace std;

int selection(int *A,int N)
{
	int minj,temp,num=0;
	for (int i=0;i<N;i++)
	{
		minj=i;
		for (int j=i;j<N;j++)
		{
			if (A[j]<A[minj]) minj=j;
		}
		temp=A[minj];A[minj]=A[i];A[i]=temp;
		if(i!=minj) num++;
	}
	return num;
}

int main (void)
{
	int N;
	cin>>N;
	int *A=new int [N];
	for (int i=0;i<N;i++)
	    cin>>A[i];
	int j=selection(A,N);
	for (int i=0;i<N;i++)
	{
	    if (i) cout<<" ";
	cout<<A[i];}
	cout<<endl;
	cout<<j<<endl;
	delete[]A;
	return 0;
}
