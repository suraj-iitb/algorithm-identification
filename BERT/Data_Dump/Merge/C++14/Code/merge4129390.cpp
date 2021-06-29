#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
vector<int> S;

int merge(int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int count=0;
  vector<int> L(S.begin()+left,S.begin()+left+n1);
  vector<int> R(S.begin()+mid,S.begin()+mid+n2);
  L.push_back(numeric_limits<int>::max());
  R.push_back(numeric_limits<int>::max());
  int i=0,j=0;
  for(int k=left;k<right;k++){
    if (L[i]<=R[j]){
      S[k]=L[i];
      i++;
    }else{
      S[k]=R[j];
      j++;
    }
    count++;
  }
  return count;
}


int mergeSort(int left,int right){
  if (left+1<right){
    int mid=(left+right)/2;
    int cnt=0;
    cnt+=mergeSort(left,mid);
    cnt+=mergeSort(mid,right);
    cnt+=merge(left,mid,right);
    return cnt;
  }
  return 0;
}

int main(){
  int n;
  cin>>n;
  S.resize(n);
  for(int i=0;i<n;i++){
    cin>>S[i];
  }
  int cnt=mergeSort(0,n);
  int i=0;
  while(i<n){
    if (i++>0) cout<<" ";
    cout<<S[i-1];
  }
  cout<<endl;
  cout<<cnt<<endl;
  return 0;
}
  

