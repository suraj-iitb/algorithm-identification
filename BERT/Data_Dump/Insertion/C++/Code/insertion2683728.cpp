#include<iostream>
int main()
{
	using namespace std;
	const int MAX=1000;
	int n,A[MAX],i,j,pos,item;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>A[i];
	for(i=0;i<n;i++)
		if(i<n-1)
			cout<<A[i]<<' ';
		else
			cout<<A[i];
	cout<<endl;
	for(i=1;i<n;i++)
	{
		item=A[i];
		pos=i-1;
		while(pos>=0&&A[pos]>item)
		{
			A[pos+1]=A[pos];
			pos--;
		}
		A[pos+1]=item;
		for(j=0;j<n;j++)
			if(j<n-1)
				cout<<A[j]<<' ';
			else
				cout<<A[j];
		cout<<endl;
	}
	return 0;
}
