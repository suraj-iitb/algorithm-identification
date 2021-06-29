#include<iostream>
int main()
{
	const int MAX=1000;
	using namespace std;
	int n,i,j,temp,count,A[MAX];
	count=0;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>A[i];
	for(i=1;i<=n-1;i++)
		for(j=n-1;j>=i;j--)
			if(A[j-1]>A[j])
			{
				{
					temp=A[j-1];
					A[j-1]=A[j];
					A[j]=temp;
				}
				count++;
			}
	for(i=0;i<n;i++)
		if(i<n-1)
			cout<<A[i]<<' ';
		else
			cout<<A[i];
	cout<<endl<<count<<endl;
	return 0;
}
