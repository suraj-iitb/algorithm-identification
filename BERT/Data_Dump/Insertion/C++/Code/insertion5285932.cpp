#include <bits/stdc++.h>
#define INF 99999999
using namespace std;
typedef long long ll;
const int MAX_N=110;
//输出a数组函数
void print(int a[],int n){
	for(int i=0;i<n;i++){
		if(i>0)
			cout<<' ';
		cout<<a[i];
	}
	cout<<endl;
}
//插入排序
void insertionSort(int a[],int n){
	for(int i=1;i<n;i++){
		//获取当前位置元素
		int v=a[i];
		//遍历ai的前面所有排序好的项，如果大于ai，则后移，直到越界或者小于ai 
		int j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		//把ai插入到空位 
		a[j+1]=v;
		//输出a数组
		print(a,n);
	}
} 

int main(){
	//n个数 
	int n;
	//数组
	int a[MAX_N];
	//输入
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	//输出a数组
	print(a,n);
	//调用插入排序 
	insertionSort(a,n);
	return 0;
}

/*
样例
6
5 2 4 6 1 3
输出 
5 2 4 6 1 3
2 5 4 6 1 3
2 4 5 6 1 3
2 4 5 6 1 3
1 2 4 5 6 3
1 2 3 4 5 6
*/ 
