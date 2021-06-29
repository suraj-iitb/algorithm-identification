#include <iostream>
using namespace std;
int n,a[100];

void print(){
	int i=0;
	while(true){
		cout<<a[i];
		i++;
		if(i<n){
			cout<<" ";
		}else{
			break;
		}
	}
	cout<<endl;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bool flag=true;
	int cont=0,send=0;
	while(flag){
		flag=false;
		for(int i=n-1;i>send;i--){
			if(a[i]<a[i-1]){
				const int tmp=a[i];
				a[i]=a[i-1];
				a[i-1]=tmp;
				flag=true;
				cont++;
			}
		}
		send++;
	}
	print();
	cout<<cont<<endl;
	return 0;
}
