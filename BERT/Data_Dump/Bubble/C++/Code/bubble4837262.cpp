#include <iostream>
using namespace std;
//冒泡排序法是从数组末尾开始的
int N=0,a[105]={0};
/*void print(){
	for(int i=1;i<=N;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
}*/
int main(){
	int i=0,j=0,res=0,flag=0;
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>a[i];
	}
	for(j=1;j<=N;j++){//最坏的情况就是把j=N循环到 
	for(i=N;i>j;i--){
        if(a[i]<a[i-1]){
        	int v=a[i-1];
        	a[i-1]=a[i];
        	a[i]=v;
        	flag=1;
        	res++;
        	//print();
		}
	}
		if(flag==0){
			break;
		}
		flag=0;
	}
	for(i=1;i<=N;i++){
		cout<<a[i];
		if(i!=N){
			cout<<' ';
		}else{
			cout<<endl;
		}
	}
	cout<<res<<endl;
	return 0;
}
