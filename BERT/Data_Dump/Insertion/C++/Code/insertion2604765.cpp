#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<stdio.h>
#include<cctype>
#include<algorithm>
#include<string.h>


using namespace std;
void insertionsort(int a[],int b);
int n;



int main()
{
	int a[101];
	while(cin>>n)
	{
	for(int i=0;i<n;i++)
		cin>>a[i];
	insertionsort(a,n);
	
	




	}
	
	


	
	
	
	



}
void insertionsort(int a[],int b)
{
	for(int i=0;i<b;i++)
		{
			int v=a[i];
		int j=i-1;
			while(j>=0&&a[j]>v)
				{
					a[j+1]=a[j];
					j--;}

						a[j+1]=v;
					for(int k=0;k<n;k++)
							{
								cout<<a[k];
					if(k!=n-1)
						cout<<" ";
					else
						cout<<endl;
					}




			
			
	}
	






}
