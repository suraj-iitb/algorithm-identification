#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int main(void)
{
	int v,e;
	int s,t,d;
	int i,j,k;
	int flg=0;
	int rin[100][100];
	
	cin>>v>>e;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++) rin[i][j]=INF;
	}
	for(i=0;i<v;i++) rin[i][i]=0;
	for(i=0;i<e;i++){
		cin>>s>>t>>d;
		rin[s][t]=d;
	}
	
	/*cout<<endl;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++) cout<<rin[i][j]<<" ";
		cout<<endl;
	}*/
	
	for(k=0;k<v;k++){ 
		for(i=0;i<v;i++){
			for(j=0;j<v;j++) if(rin[i][k]!=INF&&rin[k][j]!=INF) rin[i][j]=min(rin[i][j],rin[i][k]+rin[k][j]);
		}
	}
	
	for(i=0;i<v;i++) if(rin[i][i]!=0) flg=1; 
	
	if(flg==1) cout<<"NEGATIVE CYCLE"<<endl;
	else{
		for(i=0;i<v;i++){
			for(j=0;j<v;j++){
				if(j==0){
					if(rin[i][j]==INF) cout<<"INF";
					else cout<<rin[i][j];
				}
				else{
					if(rin[i][j]==INF) cout<<" "<<"INF";
					else cout<<" "<<rin[i][j];
				}
			}
			cout<<endl;
		}
	}
	
	return 0;
}
