#include <bits/stdc++.h>
using namespace std;
struct card{
  int x;
  char ch;
  int idx;
  bool operator <= (card a)const{
    if(x<a.x) return 1;
    if(x == a.x) return idx<=a.idx;
    return 0;
  }
};


int partition(card A[],int p,int r){
  card x = A[r];
  int i = p - 1;
  for(int j=p; j<r; j++)
    if(A[j] <= x) swap(A[++i],A[j]);
  swap(A[i+1],A[r]);
  return i+1;
}

void quickSort(card A[],int p,int r){
  if(p>=r)return;
  int q = partition(A,p,r);
  quickSort(A,p,q-1);
  quickSort(A,q+1,r);
  
}

bool same(card A[],card B[],int n){
  for(int i=0;i<n;i++)if(A[i].ch!=B[i].ch) return 0;
  return 1;
}

int main(){

  int n;
  cin>>n;
  card A[100010],B[100010];
  for(int i=0;i<n;i++)cin>>A[i].ch>>A[i].x,A[i].idx = 0;
  for(int i=0;i<n;i++)B[i] = A[i],B[i].idx = i;
  quickSort(A,0,n-1);
  quickSort(B,0,n-1);
  cout<<(same(A,B,n)? "Stable":"Not stable")<<endl;
  for(int i=0;i<n;i++)cout<<A[i].ch<<" "<<A[i].x<<endl;


  return 0;
}
