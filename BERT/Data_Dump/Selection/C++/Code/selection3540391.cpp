#include<iostream>
using namespace std;

const int MAXN=110;
int pp[MAXN]={0};
int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++) cin>>pp[i];
		int t=0;
		for(int i=0;i<n-1;i++){
			int res=i;
			for(int j=i+1;j<n;j++){
				if(pp[res]>pp[j]) res=j;
			}
			if(res!=i){
				int temp=pp[res];
				pp[res]=pp[i];
				pp[i]=temp;
				t++;
			}		
		}				
		
		for(int i=0;i<n;i++){
			if(i<n-1) cout<<pp[i]<<" ";
			else cout<<pp[i]<<endl;
		}
		cout<<t<<endl;
	}
	
	return 0;
}
