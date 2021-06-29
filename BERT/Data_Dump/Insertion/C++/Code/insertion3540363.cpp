#include<iostream>
using namespace std;

const int MAXN=100+10;
int pp[MAXN]={0};
int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++) cin>>pp[i];
		for(int i=0;i<n;i++){
				if(i<n-1)cout<<pp[i]<<" ";
				else cout<<pp[i]<<endl;
			} 
		for(int i=1;i<n;i++){
			int t=pp[i],j=i-1;
			while(j>=0&&pp[j]>t){
				pp[j+1]=pp[j];
				j--;
			}
			pp[j+1]=t;
		
			for(int i=0;i<n;i++){
				if(i<n-1)cout<<pp[i]<<" ";
				else cout<<pp[i]<<endl;
			} 
		}
	}
	return 0;
} 
