#include<iostream>
#include<vector>
#define MAX 100000
#define INF (1 << 21)
using namespace std;

struct card{
  int val;
  char c;
};

struct card a[MAX];
struct card b[MAX];

int n;

void merge(int left, int mid, int right){
  int n1 = mid -left;
  int n2 = right - mid;

  struct card r[MAX/2 + 5];
  struct card l[MAX/2 + 5];

  int i, j;
  
  for(i = 0; i < n1; i++) l[i] = a[left + i];
  for(i = 0; i < n2; i++) r[i] = a[mid + i];

  l[n1].val = INF;
  r[n2].val = INF;

  i = 0;
  j = 0;

  for(int k = left; k < right; k++){
    if(l[i].val <= r[j].val){
      a[k] = l[i++];
    }

    else a[k] = r[j++];

  }
}

void mergeSort(int left, int right){
  if(left+1 < right){
    int mid = (left + right) / 2;

    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

int partition(int p, int r){
  struct card x = b[r];
  struct card dummy;
  int i = p - 1;

  for(int j = p; j < r; j++){

    if(b[j].val <= x.val){
      i++;
      dummy = b[i];
      b[i] = b[j];
      b[j] = dummy;
    }
  }
    
    dummy = b[i+1];
    b[i+1] = b[r];
    b[r] = dummy;
  
  return i+1;
  
}

void quickSort(int p, int r){
  int q;

  if(p < r){
    q = partition(p, r);
    quickSort(p, q-1);
    quickSort(q+1, r);
  }
}

int main()
{
  int x;
  char s;
  bool flag = true;
  
  cin >> n;
  
  for(int i = 0; i < n; i++){
    cin >> s >> x;

    a[i].c = s;
    a[i].val = x;
    
    b[i].c = s;
    b[i].val = x;

  }

  mergeSort(0, n);
  quickSort(0, n-1);

  for(int i = 0; i < n; i++){
    if(a[i].c != b[i].c) flag = false;
  }

  if(flag) cout << "Stable" << endl;
  else cout << "Not stable" << endl;

  for(int i = 0; i < n; i++){
    cout << b[i].c << " " << b[i].val << endl;
  }

  return 0;

}

