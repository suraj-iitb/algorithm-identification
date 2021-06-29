#include<iostream>
using namespace std;

#define MAX 500000
#define SNTNL 2000000000

int l[MAX/2+2], r[MAX/2+2];
int cnt;

void merge(int A[], int n, int left, int middle, int right){
  int n1=middle-left;
  int n2=right-middle;

  for(int i=0; i<n1; i++)
    l[i]=A[left+i];
  for(int i=0; i<n2; i++)
    r[i]=A[middle+i];

  l[n1]=r[n2]=SNTNL;

  int i=0, j=0;

  for(int k=left; k<right; k++){
    cnt++;
    if(l[i] <= r[j])
    {
      A[k]=l[i++];
    }
    else
    {
      A[k]=r[j++];
    }
  }
}

void mergeSort(int A[], int n, int left, int right){
  if(left+1 < right)
  {
    int middle=(left+right)/2;

    mergeSort(A, n, left, middle);
    mergeSort(A, n, middle, right);
    merge(A, n, left, middle, right);
  }
}

int main(){
  int A[MAX], n, i;
  cnt=0;

  cin >> n;
  for(i=0; i<n; i++)
    cin >> A[i];

  mergeSort(A, n, 0, n);

  for(i=0; i<n; i++){
    if(i)
      cout << " ";
    cout << A[i];
  }

  cout << endl;

  cout << cnt << endl;

  return 0;
}

