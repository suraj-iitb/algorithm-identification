#include <iostream>
#include <cstring>
using namespace std;
int l[100];
int main()
{
  int N;
  while(cin >> N){
    memset(l,0,sizeof(l));
    for(int i=0; i<N; i++){
      cin >> l[i];
    }
    for(int k = 0; k<N; k++){
      if(k!=0) cout << " ";
      cout << l[k];
    }
    cout << endl;
    for(int j=1; j<N; j++){
      int key = l[j];
      int i = j-1;
      while(i >= 0 && l[i] > key){
        l[i+1] = l[i];
        i--;
      }
      l[i+1] = key;
      for(int k = 0; k<N; k++){
        if(k!=0) cout << " ";
        cout << l[k];
      }
      cout << endl;
    }
  }
  return 0;
}
