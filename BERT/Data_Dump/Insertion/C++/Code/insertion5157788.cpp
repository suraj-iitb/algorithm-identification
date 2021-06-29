#include<iostream>
using namespace std;
int main()
{
 	int a[100],n,key;
 	cin>>n;
 	for(int i=0;i<n;i++)
 	 	cin>>a[i];
 	for(int x=0;x<n-1;x++)
  		cout<<a[x]<<" ";
 		cout<<a[n-1]<<endl;
 	for(int i=1;i<n;i++)
 	{
  		int key=a[i],j=i-1;
  	while(a[j]>key&&j>=0)
  		{
  	 		a[j+1]=a[j];
   			j--;
  		}
  	a[j+1]=key;
  	for(int x=0;x<n-1;x++)
  	 	cout<<a[x]<<" ";
  	cout<<a[n-1]<<endl;;
 }
}
