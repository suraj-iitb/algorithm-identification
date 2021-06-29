#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(obj) (obj).begin(),(obj).end()
int cnt=0;

void merge(vector<int> &A,int left, int mid,int right){
      int n1=mid-left;
      int n2=right-mid;
      vector<int> L(n1);
      vector<int> R(n2);
      for(int i=0;i<n1;i++)  L.at(i)=A.at(left+i);
      for(int i=0;i<n2;i++) R.at(i)=A.at(mid+i);
      L.push_back(1e9);
      R.push_back(1e9);
      int i=0;
      int j=0;
      for(int k=left;k<right;k++){
        cnt++;
          if(L.at(i)<=R.at(j)) {
              A.at(k)=L.at(i);
              i++;
          }
          else{
              A.at(k)=R.at(j);
              j++;
          }
      }
      return;
    }

void mergeSort(vector<int> &A,int left,int right){
      if(left+1<right){
          int mid=(left+right)/2;
          mergeSort(A,left,mid);
          mergeSort(A,mid,right);
          merge(A,left,mid,right);
      }
      return;
      }

  int main(){
      cin.tie(0);
      ios::sync_with_stdio(false);
      int n;
      cin>>n;
      vector<int> A(n);
      rep(i,n) cin>>A.at(i);
      mergeSort(A,0,n);
      for(int i=0;i<n;i++){
        if(i) cout<<" ";
        cout<<A.at(i);
      }
      cout<<endl<<cnt<<endl;
      return 0;
  }

