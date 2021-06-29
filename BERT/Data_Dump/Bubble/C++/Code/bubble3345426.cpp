#include <iostream>
using namespace std;
int A[100];
int main()
{
	int N,i;
	cin >> N;
	for(i=0;i<N;i++)
		cin >> A[i];
	int flag=1,j,t,count=0;
	while(flag)
	{
		flag=0;
		for(j=1;j<N;j++)
		{
			if(A[j]<A[j-1])
			{
				t=A[j];
				A[j]=A[j-1];
				A[j-1]=t;
				flag=1;
				count++;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		if(i>0)
			cout <<" ";
		cout << A[i];
	} 
	cout<<endl;
	cout<<count<<endl;
	return 0;
} 
