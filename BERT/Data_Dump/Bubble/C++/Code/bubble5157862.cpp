#include<iostream>
using namespace std;
int n,k=0;
int a[101];
void BubbleSort(int *a)
{
	for(int j=0;j<(n-1);j++)         //循环（n-1）轮 
		{
			for(int i=0;i<(n-1-j);i++)    //一轮循环（n-j）次 
			{
				if(a[i]>a[i+1])
				{
					k++;
					int t=a[i];
					a[i]=a[i+1];
					a[i+1]=t;      //升序排序 
				}      
			}    					
		}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	BubbleSort(a);
	for(int i=0;i<n-1;i++)
		cout<<a[i]<<" ";
	cout<<a[n-1]<<"\n"<<k<<endl;
}
