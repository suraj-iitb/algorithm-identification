#include <iostream>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int v[100][100];
int V;
int main(){
    int E,s,t,d;
    int inf=2000000000;
    cin>>V>>E;
    f(i,0,V){
        f(j,0,V){
            if(i==j){
                v[i][j]=0;
            }
            else{
                v[i][j]=inf;
            }
        }
    }
    f(i,0,E){
        cin>>s>>t>>d;
        v[s][t]=d;
    }
    f(k,0,V){
       f(i,0,V){
           f(j,0,V){
               if(v[i][k]!=inf&&v[k][j]!=inf){
                   v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
               }
           }
       } 
    }
    f(i,0,V){
        if(v[i][i]<0){
            cout<<"NEGATIVE CYCLE"<<endl;
            return 0;
        }
    }
    
    f(i,0,V){
        f(j,0,V){
            if(j){
                cout<<" ";
            }
            if(v[i][j]>=inf){
                cout<<"INF";
            }
            else{
                cout<<v[i][j];
            }
        }
        cout<<endl;
    }
    
    return 0;
}

