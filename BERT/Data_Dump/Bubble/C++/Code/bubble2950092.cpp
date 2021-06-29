# include <iostream>
using namespace std;
void swap(int* x,int* y){
	int tmp;
	tmp =*x; *x =*y; *y =tmp;
}
int main(){
	int n;
	cin >>n;
	int x[n]={},p=1,sum =0;
	for(int i=0;i<n;i++){
		cin >>x[i]; 
	}
	while(p!=0){
		p=0;
		for(int i=n-1;i>0;i--){
			if(x[i]<x[i-1]){
				swap(&x[i],&x[i-1]);
				p=1; sum++;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(i==0) cout<<x[i];
		else cout<<" "<<x[i];
	}
	cout<<"\n"<<sum<<"\n";

}
