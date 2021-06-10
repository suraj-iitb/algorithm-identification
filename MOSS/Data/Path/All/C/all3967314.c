#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 100
#define INFTY 1ll<<31

int n;
long long d[MAX][MAX];

void warshallFloyd(){
  
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      if(d[i][k] == INFTY) continue;
      for(int j=0;j<n;j++){
        if(d[k][j] == INFTY) continue;
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }

}



int main(void){

  int e, u, v;
  long long c;
  cin >> n >> e;


  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      d[i][j] = INFTY;
    }
  }

  for(int i=0;i<n;i++){
    d[i][i] = 0;
  }

  for(int i=0;i<e;i++){
    cin >> u >> v >> c;
    d[u][v] = c;
  }

  warshallFloyd();

  bool negative_loop=false;
  
  for(int i=0;i<n;i++){
    if( d[i][i] < 0){
      negative_loop = true;
      break;
    }
  }

  if(negative_loop){
    cout << "NEGATIVE CYCLE" << endl;
  }else{
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if( j!= 0){
          cout << " ";
        }
        if(d[i][j] == INFTY){
          cout << "INF";
        }else{
          cout << d[i][j];
        }      
      }
      cout << endl;
    }
  }  
  
  return 0;
}

