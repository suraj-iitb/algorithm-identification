#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  vector<int> sort;
  cin >> n;

  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    sort.push_back(a);
  }
  for(int i=0; i<n; i++){
    cout << sort[i];
    if (i != n-1){
      cout << " ";
    }
  }
  cout << endl;

  for(int i=1; i<n; i++){
    int v = sort[i];
    int j = i-1;
    while(j>=0 && sort[j] > v){
      sort[j+1] = sort[j];
      j--;
      sort[j+1] = v;
    }
    for(int k=0; k<n; k++){
      cout << sort[k];
      if(k != n-1){
        cout << " ";
      }
    }
    cout << endl;
  }

  return 0;
}

