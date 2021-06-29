#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100
#define INF 2e+11
int V,E;
long long M[MAX][MAX];
void search(){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            if(M[i][k]==INF) continue;
            for(int j=0;j<V;j++){
                if(M[k][j]==INF) continue;
                M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
            }
        }
    }
}
int negative(int x){
    if(M[x][x]<0) return 1;
    else return 0;
}
int main(){
   int s,t,d,count=0;;
   cin>>V>>E;
   for(int i=0;i<V;i++){
       for(int j=0;j<V;j++){
           if(i==j) M[i][j]==0;
           else M[i][j]=INF;
       }
   }
   for(int i=0;i<E;i++){
       cin>>s>>t>>d;
       M[s][t]=d;
   }
   search();
   for(int i=0;i<V;i++){
       negative(i);
       if(negative(i)!=0) count+=1;
   }
   if(count==0){
       for(int i=0;i<V;i++){
           for(int j=0;j<V;j++){
               if(j>0) cout<<" ";
               if(M[i][j]==INF) cout<<"INF";
               else cout<<M[i][j];
           }
           cout<<endl;
       }
   }
   else cout<<"NEGATIVE CYCLE"<<endl;
}
