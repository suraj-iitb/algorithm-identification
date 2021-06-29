#include<bits/stdc++.h>
#define mx 2000000000
using namespace std;
int main(void)
{
	int v,e;
	int a,b,c,d[101][101],i,j,k;
	
	cin>>v>>e;
	
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			if(i==j) d[i][j]=0;
			else d[i][j]=mx;
		}
	}
	
	for(i=0;i<e;i++){
		cin>>a>>b>>c;
		d[a][b]=c;
	}	
		
	for(k=0;k<v;k++){
		for(i=0;i<v;i++){
			for(j=0;j<v;j++){
				if(d[i][k]==mx||d[k][j]==mx) continue;
				else d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	
	int flg=0;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			if(i==j&&d[i][j]<0) flg=1;
		}
	}
	
	if(flg==1) cout<<"NEGATIVE CYCLE"<<endl;
	
	if(flg==0){
		for(i=0;i<v;i++){
			for(j=0;j<v;j++){
				if(mx==d[i][j]&&j==0) cout<<"INF";
				else if(mx!=d[i][j]&&j==0) cout<<d[i][j];
				else if(mx==d[i][j]&&j!=0) cout<<" "<<"INF";
				else cout<<" "<<d[i][j];
			}
			cout<<endl;
		}	
	}
	
	return 0;
}	
