#include<iostream>
#include<math.h>
#include<iomanip>
#include<string.h>
#include<cstdio>
#include<cstdlib>
#include<stack>

using namespace std;

int sum = 0;

void merge(int a[], int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int l[n1], r[n2];
  for(int i = 0; i < n1; i++){
    l[i] = a[left + i];
  }
  l[n1] = 1000000000;
  for(int i = 0; i < n2; i++){
    r[i] = a[mid + i];
  }
  r[n2] = 1000000000;

  int j = 0, k = 0;
  for(int i = 0; i < n2 + n1; i++){
    if(l[j] <= r[k]){
      a[left + i] = l[j];
      j++;
    }
    else{
      a[left + i] = r[k];
      k++;
    }
    sum++;
  }
}

void mergesort(int a[], int left, int right){
  if(left + 1 < right){
    int mid = (left + right) / 2;
    mergesort(a, left, mid);
    mergesort(a, mid, right);
    merge(a, left, mid, right);
  }
}


int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  mergesort(a, 0, n);


  for(int i = 0; i < n - 1; i++){
    cout << a[i] << " ";
  }
  cout << a[n - 1] << endl;
  cout << sum << endl;


}
