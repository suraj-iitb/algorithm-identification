#include<iostream>
using namespace std;
#define maxx 10
int A[maxx];
int cnt=0;//交换次数 
//选择排序：找出未排序部分最小值的序号
//由于直接交换两个不相邻的元素，不具有稳定性，时间复杂度为O(n^2)
//冒泡排序从局部入手减少逆序元素，选择排序放眼大局逐个选择最小值
//但都有通过i次外层循环，从数据中顺次求出i个最小值
//插入排序是通过i次外层循环，直接将原数组的i个元素重新排序，数据依赖性大 
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
//先找后交换 
int selectionSort(int num[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int flag=0;
		int v=num[i];
		int kk=i;//未排序部分最小值的序号 
		for(int j=i+1;j<n;j++)
		{
			if(num[j]<v)
			{
				flag=1;
				v=num[j];
				kk=j;	
			} 
		}
		if(flag==1)
		{
			int tt=num[kk];
			num[kk]=num[i];
			num[i]=tt;
			cnt++;
		}
	} 
	return 0;
}
//边找边交换,这种不叫选择排序 
/*int selectionSort(int num[],int n)
{
	for(int i=0;i<n;i++)
	{
		int minj=i;
		for(int j=i+1;j<n;j++)
		{
			if(num[j]<num[minj])
			{
				int tt=num[minj];
				num[minj]=num[j];
				num[j]=tt;
				cnt++;//此处cnt含义发生变化，总共的交换次数 
			}
			
		}	
	}	
} */
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	selectionSort(A,n);
	trace(A,n);
	return 0;
}
 
