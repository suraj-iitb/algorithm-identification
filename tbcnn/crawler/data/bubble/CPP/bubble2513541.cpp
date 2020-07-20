#include<iostream>
using namespace std;
int main()
{
	int a[200]={0},n,i;
	cin>>n;
	for(i=0;i<n;i++)  cin>>a[i]; 
	int flag=1,count=0;
	while(flag)
	{
		flag=0;
		for(i=n-1;i>0;i--)
		{
			if(a[i]<a[i-1])
			{
				int h=a[i];
				a[i]=a[i-1];
				a[i-1]=h;
				flag=1;
				count++;
			} 	
		} 
	}
	for(i=0;i<n-1;i++) cout<<a[i]<<" ";
	cout<<a[n-1]<<endl;
	cout<<count<<endl;
	return 0;
}
