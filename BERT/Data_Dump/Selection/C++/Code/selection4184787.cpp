#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int selectionSort(vector <int> &a,int n){
  int count =0;
  for(int i =0;i < n-1;i++){
    int minj =i; //探索される最小値を格納したい場所
    for(int j =i;j<n;j++){
      if (a.at(j)<a.at(minj)){
        minj =j;
      }
    }
    if(minj != i){
      swap(a.at(i),a.at(minj));
      count++;
    }
  }
return count;
}



int main(){
  int n ,counter;
  cin >>n;
  vector <int> a(n);
  rep(i,n)cin >>a.at(i);
  counter = selectionSort(a , n);
  rep(i,n){
    if(i)cout<<" ";
    cout <<a.at(i);
  }
  cout<<endl;
  cout <<counter<<endl;
}

