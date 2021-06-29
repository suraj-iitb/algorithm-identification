#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt;//记录交换次数 
void print(int A[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<A[i]<<(i==n-1?"\n":" ");
	}
}
void bubblesort(int A[],int n){
	bool flag=1;//做标记，如果数组本身就是从小到大的顺序排列，则程序终止
	for(int i=0;flag;i++){//有序区的尾端 
		flag=0;
		for(int j=n-1;j>i;j--){//从末端开始比较到无序区的开头 
			if(A[j]<A[j-1]){
			swap(A[j],A[j-1]);
				flag=1;
				cnt++;
			}
		}
	} 
}
int main()
{
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	bubblesort(A,n);
	print(A,n);
	cout<<cnt<<endl;
   return 0;
}

