#include<iostream>
using namespace std;
int a[105];




int main()
{
	int n,i,j,v,k;
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
	}
   for(i=0;i<n;i++)
   {
   	if(i!=0)
   	cout<<" ";
   	cout<<a[i];
   }
   cout<<endl;
   for(i=1;i<n;i++)
   {
   	v=a[i];
   	j=i-1;
   	while(j>=0 && a[j]>v)
   	{
   		  	   a[j+1]=a[j];  	 
   		j--;
	   }
	   a[j+1]=v;
	   for(k=0;k<n;k++)
	   {
	   	if(k!=0)
	   	cout<<" ";
	   	cout<<a[k];
	   }
	   cout<<endl;
   }
}
