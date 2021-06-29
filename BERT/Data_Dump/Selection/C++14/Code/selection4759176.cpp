#include<iostream>
#include<vector>

using namespace std;

void swap(int &a,int &b,int &count){
    int tmp = a;
    a = b;
    b = tmp;
    count++;
}

void show(vector<int> vec){
    int cnt = 0;
    for(auto a: vec){
        cout << a;
        if(cnt!= vec.size()-1) cout << " ";
        else cout << endl;
        cnt++;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i < n;i++){
        cin >> A.at(i);
    }
    int cnt = 0,min_idx;
    for(int i=0;i < A.size();i++){
      min_idx = i;
      for(int j=i;j < A.size();j++){
        if(A.at(j) < A.at(min_idx)){
          min_idx = j;
        }
      }
      if(i != min_idx) swap(A.at(i),A.at(min_idx),cnt);
    }
    show(A);cout << cnt << endl;
    return 0;
}
