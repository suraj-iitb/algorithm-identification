#include <iostream>
#include <climits>

using namespace std;
#define MAX 100
int n,k,u,v,w;
int D[MAX+10][MAX+10],W[MAX+10][MAX+10];

int Fkoyd()
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            if(W[i][k]==INT_MAX) continue;
            for(int j=0;j<n;j++)
            {
               if(W[k][j]==INT_MAX) continue;
               W[i][j]=min(W[i][j],W[i][k]+W[k][j]);
            }
        }
    }
}

int main()
{
    int negative=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
    {

        W[i][j]=(i==j)?0:INT_MAX;
    }
    for(int i=0;i<k;i++)
    {
        cin>>u>>v>>w;
        W[u][v]=w;
    }
    Fkoyd();
    for(int i=0;i<n;i++)
      if(W[i][i]<0) negative=1;


    if(negative) cout<<"NEGATIVE CYCLE"<<endl;
    else
    {
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<n;j++)
          {
            if(j) cout<<" ";
            if(W[i][j]==INT_MAX) cout<<"INF";
            else cout<<W[i][j];
          }
          cout<<endl;
        }
    }
    return 0;
}

