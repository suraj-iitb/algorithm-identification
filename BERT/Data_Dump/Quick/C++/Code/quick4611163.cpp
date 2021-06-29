#include<iostream>
#include<string>

#define rep(i, n) REP(i, 0, n)
#define REP(i, a, n) for(int i = a ; i < (int)n ; i++)
#define INF 1e9
#define MAX_N 100000

using namespace std;

struct Card{
  char c;
  int num;
};

int n;
Card A[100000], B[100000];
int comp;
Card l[MAX_N/2+2];
Card r[MAX_N/2+2];

void merge(int left, int right, int mid){
  rep(i, mid-left){
    l[i] = B[left + i];
  }
  rep(i, right-mid){
    r[i] = B[mid + i];
  }

  l[mid-left].num = r[right-mid].num = INF;
  
  int left_idx, right_idx;
  left_idx = right_idx = 0;
  REP(i,left,right){
    comp++;
    if(l[left_idx].num <= r[right_idx].num){
      B[i] = l[left_idx];
      left_idx++;
    }else{
      B[i] = r[right_idx];
      right_idx++;
    }
  }
}

void mergeSort(int left, int right){
  if(right - left > 1){
    int mid = (right + left)/2;
    mergeSort(left, mid);     
    mergeSort(mid, right);    
    merge(left, right, mid);  
  }
}

int partition(int p, int r){
  int i;
  i = p-1;
  REP(j, p, r){
    if(A[j].num <= A[r].num){
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i+1], A[r]);
  
  return i+1;
}

void quickSort(int p, int r){
  if(r - p > 0){
    int ret = partition(p, r);
    quickSort(p, ret-1);
    quickSort(ret+1, r);
  }
}

bool compare(Card l, Card r){
  return (l.num <= r.num);
}

signed main(){

  cin >> n;
  rep(i, n){
    cin >> A[i].c >> A[i].num;    
    B[i].c = A[i].c;
    B[i].num = A[i].num;
  }
  
  quickSort(0, n-1);
  mergeSort(0, n);

  bool flag = false;
  rep(i, n){
    if(A[i].c != B[i].c) flag = true;
  }
  
  if(flag) cout << "Not stable" << endl;
  else cout << "Stable" << endl;

  rep(i, n){
    cout << A[i].c << " " << A[i].num << endl;
  }

}
