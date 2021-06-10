#include<bits/stdc++.h>
#define mm 1e18
using namespace std;
long long minn(long long a,long long b){
	      if (a<b)
	         return a;
	      else
	         return b;
}
int main(){
	int n,m,x,y,z;
	long long f[105][105];
    cin>>n>>m;
	for (int i=0; i<n; i++)
	    for (int j=0; j<n; j++)
	        f[i][j]=mm;
	
	while (m--){
		  cin>>x>>y>>z;
		  f[x][y]=z;
	}
	for (int i=0; i<n; i++)
	    f[i][i]=0;
	for (int k=0; k<n; k++)
	    for (int i=0; i<n; i++)
	        for (int j=0; j<n; j++)
	            if (f[i][k]!=mm && f[k][j]!=mm)
	               f[i][j]=minn(f[i][j],f[i][k]+f[k][j]);
	int ok=1;
	for (int i=0; i<n; i++)
	    if (f[i][i]<0){
	    	ok=0; break;
		}
	if (ok){
	   for (int i=0; i<n; i++){
	   	   if (f[i][0]==mm)
	   	      cout<<"INF";
	   	   else
	   	      cout<<f[i][0];
           for (int j=1; j<n; j++)
               if (f[i][j]==mm)
                  cout<<" INF";
               else
                  cout<<' '<<f[i][j];
           cout<<'\n';
	   }
	}
	else
	   cout<<"NEGATIVE CYCLE"<<'\n';
	return 0;
}
