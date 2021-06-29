#include<iostream>
using namespace std;

const int MAXN=110;
int pp[MAXN]={0};
int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++) cin>>pp[i];
		int temp=0;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				if(pp[j]>pp[j+1]){
					int t=pp[j];
					pp[j]=pp[j+1];
					pp[j+1]=t;
					temp++;	
				}
			}
		}
		for(int i=0;i<n;i++){
			if(i<n-1){
				cout<<pp[i]<<" ";
			}else{
				cout<<pp[i]<<endl;
			}
		}
		cout<<temp<<endl;
	}
	
	return 0;
}
