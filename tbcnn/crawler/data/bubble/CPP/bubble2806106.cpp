#include <iostream>
using namespace std;

int buttle(int *A,int N)
{
	int temp,num=0;
	bool flag=true;
	for (int i=0;flag;i++)
	{
		flag=false;
		for (int j=N-1;j>=i+1;j--)
		{
			if (A[j-1]>A[j])
			{
				temp=A[j];A[j]=A[j-1];A[j-1]=temp;
				flag=true;
				num++;
			}
		}
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
	int j=buttle(A,N);
	for (int i=0;i<N;i++)
	{
	    if (i) cout<<" ";
	cout<<A[i];}
	cout<<endl;
	cout<<j<<endl;
	delete[]A;
	return 0;
}
