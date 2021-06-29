//////////////////////////      一      //////////////
/*
注意点：
1. 注意读题（对应1z//2.）
2.插入排序的插入位置（对应1z//1.）
3.插入排序的升降序控制（对应 1z//3.   1z//4.） 
*/
//------------------1z-------------- 
/*
#include<iostream>
using namespace std;
int a[105];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int i=0;i<n-1;++i){						//4.原来没打 
		cout<<a[i]<<' ';						//4.					 
	}											//4.					
	cout<<a[n-1]<<endl;							//4.
	for(int i=1;i<n;++i){
		int t=a[i];
		int j=i-1;
		while(j>=0&&a[j]>t){					//3.升序是">",降序是"<" 
			a[j+1]=a[j];						 
			--j;
		}
		a[j+1]=t;								//1.后一位（原打成a[j]） 
		for(int i=0;i<n-1;++i){					//2.此循原来写外面了 
			cout<<a[i]<<' ';					//2. 
		}										//2.
		cout<<a[n-1]<<endl;						//2.
	}
	return 0;
}
*/
/////////////////////    答案    /////////////// 
/*
注意点：
1. 
*/
//----------------------自打1------------------ 
/*
#include<cstdio>
void trace(int A[],int N){
	for(int i=0;i<N;++i){
		if(i>0) printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
} 
void insertionSort(int A[],int N){
	int v,j;
	for(int i=1;i<N;++i){
		v=A[i];
		j=i-1;
		while(j>=0&&A[j]>v){
			A[j+1]=A[j];
			--j;
		}
		A[j+1]=v;					//2.是A[j+1](原打成A[j]) 
		trace(A,N);
	}
}
int main(){
	int n;
	scanf("%d",&n);					//1.别忘输入 
	int A[100];
	for(int i=0;i<n;++i){
		scanf("%d",&A[i]);
	}
	trace(A,n);
	insertionSort(A,n);
	return 0;
	
}
*/
//---------------------标准答案--------------------

#include<stdio.h>

/* 按顺序输出数组元素 */
void trace(int A[],int N){
	int i; 
	for(i=0;i<N;++i){
		if(i>0) printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
} 

/* 插入排序 */
void insertionSort(int A[],int N){
	int j,i,v;
	for(i=1;i<N;++i){
		v=A[i];
		j=i-1;
		while(j>=0&&A[j]>v){
			A[j+1]=A[j];
			--j;
		}
		A[j+1]=v;
		trace(A,N);
	}
}

int main(){
	int N,i,j;
	int A[100];
	
	scanf("%d",&N);
	for(int i=0;i<N;++i) scanf("%d",&A[i]);
	
	trace(A,N);
	insertionSort(A,N);
	
	return 0;
}
