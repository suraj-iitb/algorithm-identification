#include<iostream>
using namespace std;
#define M 500000
#define SE 1000000000

int LI[M/2+2],RI[M/2+2];
int count;

void merge(int X[],int num,int left,int mid,int right){
  int ml = mid - left;
  int rm = right - mid;
  int i,k,j=0;
    for(i=0;i<ml;i++){
      LI[i] = X[left + i ];
    }
  for( i=0;i<rm;i++){
    RI[i] = X[mid +i];
  }
  LI[ml] = RI[rm] = SE;
  i =0;
  

  for(k = left;k<right;k++){
    count++;
    if(LI[i] <= RI[j]){
      X[k] = LI[i++];
    }
    else{
      X[k]=RI[j++];
    }
  }
}

void mergeSort(int X[],int n,int left, int right){
  if(left+1 < right){
    int mid = (left + right )/2;
    mergeSort(X,n,left,mid);
    mergeSort(X,n,mid,right);
    merge(X,n,left,mid,right);
  }
}

int main(){
  int X[M],num,i;
  count =0;

  cin >> num;
  for(i=0;i<num;i++){
    cin >> X[i];
  }

  mergeSort(X,num,0,num);

  for(i=0;i<num;i++){
    if(i){
      cout<< " ";
    }
      cout << X[i];
    }
    cout << endl;

    cout << count << endl;

    return 0;

  }

