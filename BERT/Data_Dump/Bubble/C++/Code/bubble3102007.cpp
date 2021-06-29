#include<iostream>
using namespace std;
#define maxn 10
int A[maxn];
int cnt=0;
int trace(int num[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(i>0)
		cout<<" ";
		cout<<num[i];
	}
	cout<<endl<<cnt<<endl;
	return 0;
}

//冒泡排序：稳定排序(仅对相邻元素进行比较和交换) ，时间复杂度O(n^2), 
//冒泡排序中的交换次数又称逆序数或反序数，可用于体现数列的错乱程度。
 
//使用flag的冒泡排序法
 
int BubbleSort(int num[],int n)
{
	int flag=1;//存在顺序相反的相邻元素
	while(flag)
	{
		flag=0;
		for(int j=n-1;j>=1;j--)
		{
			if(num[j]<num[j-1])//改为<=算法会失去稳定性 
			{
				cnt++;
				int tt=num[j-1];
				num[j-1]=num[j];
				num[j]=tt;
				flag=1;
			}	
		}
	 } 
}
/*int BubbleSort(int num[],int n)
{
	
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(num[j]<num[j-1])
			{
				cnt++;
				int tt=num[j-1];
				num[j-1]=num[j];
				num[j]=tt;
			}
		}
		
	}
	return 0;
}*/
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	BubbleSort(A,n);
	trace(A,n);
	return 0;
}
