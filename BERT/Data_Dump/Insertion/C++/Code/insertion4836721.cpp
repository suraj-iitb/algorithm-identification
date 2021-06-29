#include <iostream>
using namespace std;
int N=0,a[105]={0};
void print(){
	for(int i=0;i<N;i++){
		if(i!=N-1){
			cout<<a[i]<<' ';
		}else{
			cout<<a[i]<<endl;
		}
	}
}
int main(){
	int i=0,j=0;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>a[i];
	}
	print();
	for(i=1;i<=N-1;i++){
		int v=a[i];
		for(j=i-1;j>=0;j--){
			if(a[j]>v){
				a[j+1]=a[j];
				a[j]=v;
			}
		}
		print();
	}
}
