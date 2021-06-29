#include <iostream>
using namespace std;
int N=0,a[105]={0};
void print(){
    for(int i=1;i<=N;i++){
    	cout<<a[i];
    	if(i!=N){
    		cout<<' ';
		}else{
			cout<<endl;
		}
	}	
}
int main(){
	cin>>N;
	int minv=0,minj=0,res=0,i=0,j=0,flag=0;
	for(i=1;i<=N;i++){
		cin>>a[i];
	}
	for(i=1;i<=N;i++){
		flag=0;
		minj=i;
		for(j=i+1;j<=N;j++){
			if(a[j]<a[minj]){
				minj=j;minv=a[minj];
				flag=1;
			}
		}
		if(flag){
		a[minj]=a[i];//最小的放在未排序的第一位 
		a[i]=minv;
		res++;
		//print();
	}
	}
	print();
	cout<<res<<endl;
	return 0;
}
