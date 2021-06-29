#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
// using ll = long long;
// using P = pair<int, int>;


void print(int vec[],int n){
    rep(i,n){
        if(i > 0) cout << " ";
        cout << vec[i];
    }
    cout << endl;
}

void insertionSort(int vec[],int n){
    for(int i = 1; i < n; i++){
        int v = vec[i];
        int j = i - 1;
        while(j >= 0 && vec[j] > v){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = v; 
        print(vec,n);
    }
}

int main(){
  int n;
  cin >> n;
  int vec[n];
  rep(i,n) cin >> vec[i];
  print(vec,n);
  insertionSort(vec,n);


}
