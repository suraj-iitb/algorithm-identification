#include <bits/stdc++.h>
#define INF 99999999
using namespace std;
typedef long long ll;
const int MAX_N=110;
//冒泡排序(升序) 返回交换次数 
int bubbleSort(int a[],int n){
	int cnt=0;
	int f=1;
	//标记为1就继续排序 
	for(int i=0;f;i++){
		//修改标记为0 
		f=0;
		//遍历从n-1到1 
		for(int j=n-1;j>=i+1;j--)
			//如果后大于前，交换前后值 
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
				//交换次数++ 
				cnt++;
				//如果交换了，修改标记为1，表示还没有冒泡结束 
				f=1;
			}
	}
	return cnt;
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
	//调用冒泡排序
	int cnt=bubbleSort(a,n);
	//输出 
	for(int i=0;i<n;i++){
		if(i)
			cout<<' ';
		cout<<a[i]; 
	}
	cout<<'\n'<<cnt<<endl;
	return 0;
}

/*
样例
5
5 3 2 4 1
输出
1 2 3 4 5
8 
*/ 
