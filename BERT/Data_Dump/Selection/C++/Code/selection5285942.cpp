#include <bits/stdc++.h>
#define INF 99999999
using namespace std;
typedef long long ll;
const int MAX_N=110;
//选择排序(升序) 返回交换次数 
int selection(int a[],int n){
	int cnt=0;
	//遍了每个位置，每次选出i到n-1中的最小值放到i的位置 
	for(int i=0;i<n-1;i++){
		//i~n-1的最小值下标 
		int minj=i;
		//找最小值 
		for(int j=i;j<n;j++)
			if(a[j]<a[minj])
				minj=j;
		//交换位置
		if(minj!=i) {
			swap(a[i],a[minj]);	
			cnt++;
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
	//调用选择排序
	int cnt=selection(a,n);
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
6
5 6 4 2 1 3
输出
1 2 3 4 5 6
4
*/
