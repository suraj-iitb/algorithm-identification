#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define MAX 100
#define Infty (1LL<<32)

int n;
long long A[MAX][MAX];

void floyd(){
    for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        if(A[i][k]==Infty)continue;
        for(int j=0;j<n;j++){
        if(A[k][j]==Infty)continue;  
        A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
    }
    }
    }
}



int main(){
    int q;
    int s,t,d;
    
    cin>>n>>q;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=((i==j)?0:Infty);
        }
    }
    
    for(int i=0;i<q;i++){
     cin>>s>>t>>d;
     A[s][t]=d;
    }
    
     floyd();

    bool negative = false;
    for(int i=0;i<n;i++){
        if(A[i][i]<0)negative = true;
    }
    
    if(negative){
        cout<<"NEGATIVE CYCLE"<<endl;
    }
    else {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j)cout<<" ";
                if(A[i][j]==Infty)cout<<"INF";
                else cout<<A[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
    

