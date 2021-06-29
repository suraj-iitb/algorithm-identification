#include<iostream>
#include<vector>
#define INF 1000000000
#define nmax 500005
using namespace std;

int n;
int cnt = 0;
int a[nmax];

void merge(int left, int mid, int right){
  int n1 = mid -left;
  int n2 = right - mid;
  int l[nmax];
  int r[nmax];

  int i, j;
  
  for(i = 0; i < n1; i++) l[i] = a[left + i];
  for(i = 0; i < n2; i++) r[i] = a[mid + i];

  l[n1] = INF;
  r[n2] = INF;

  i = 0;
  j = 0;

  for(int k = left; k < right; k++){
    if(l[i] <= r[j]) a[k] = l[i++];

    else a[k] = r[j++];

    cnt++;
    
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

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  mergeSort(0, n);

  for(int i = 0; i < n; i++){
    if(i) cout << " ";

    cout << a[i];
  }

  cout << endl;
  cout << cnt << endl;
  

  return 0;

}

