# include<iostream>
# define N 10000000
# define INF 1000000000
using namespace std;

int n, S[N], cnt=0;
void merge(int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1], R[n2];

  for(int i=0; i<n1; i++) L[i] = S[left+i];
  for(int i=0; i<n2; i++) R[i] = S[mid+i];
  L[n1] = INF;
  R[n2] = INF;
  
  for(int k=left, i=0, j=0; k<right; k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i++;
    }else{
      S[k] = R[j];
      j++;
    }
    cnt++;
  }
  return;
}
void merge_sort(int left, int right){
  if(left+1 < right){
    int mid = (left + right)/2;
    merge_sort(left, mid);
    merge_sort(mid, right);
    merge(left, mid, right);
  }
  return;
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++) scanf("%d",&S[i]);
    merge_sort(0, n);
    for(int i=0; i<n-1; i++) printf("%d ",S[i]);
    printf("%d\n",S[n-1]);
    printf("%d\n",cnt);
    return 0;
}

