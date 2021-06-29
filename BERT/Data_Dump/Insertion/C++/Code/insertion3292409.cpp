#include <iostream>
using namespace std;
int main(){
	int N,v,j=0;
	cin>>N;
	int *p1;
	p1=new int[N];
	for(int a=0;a<N;a++){
		cin>>p1[a];
	}
	for(int a=0;a<N-1;a++){
		cout<<p1[a]<<" ";
	}
	cout<<p1[N-1]<<endl;
	for(int i=1;i<N;i++){
		v=p1[i];
		j=i-1;
		while(j>=0&&p1[j]>v){
			p1[j+1]=p1[j];
			j--;

		}
		p1[j+1]=v;
		for(int a=0;a<N-1;a++){
			cout<<p1[a]<<" ";
		}
		cout<<p1[N-1]<<endl;
	}


}
