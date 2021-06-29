#include<iostream>
using namespace std;
void print(int a[],int n)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<a[n-1]<<endl;
 } 
int main()
{
	int n,i,j,tag,k;
	int *p;
	cin>>n;
	p = new int [n];
	for(i=0;i<n;i++)
	cin>>p[i];
	print(p,n);
	for(i=1;i<n;i++)
	{
		tag = p[i];
		j=i-1;
		while(j >= 0 && p[j] > tag )
		{
			p[j+1] = p[j];
			j--;
		}
		p[j+1] = tag;
		print(p,n);
	}
	delete [] p;
	return 0;
 } 
