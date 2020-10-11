#include<stdio.h>

#define N 500000

void merge(int *A,int right,int left,int mid);
void MS(int *A,int left,int right);

int cnt=0;

int main(){
int n,A[N],i,j,k,left,right,mid;

scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
MS(A,0,n);
for(i=0;i<n;i++){
    if(i == 0)printf("%d",A[i]);
    else printf(" %d",A[i]);
}
printf("\n%d\n",cnt);
    return 0;
}

void merge(int *A,int right,int left,int mid){

int n1,n2,i,j,k;

n1 = mid - left;
n2 = right - mid;

int L[n1],R[n2];

for(i=0;i<n1;i++)L[i] = A[left + i];
for(i=0;i<n2;i++)R[i] = A[mid + i];

L[n1] = R[n2] = 999999999;

i = j = 0;

for(k = left; k < right ; k++){
    if(L[i] <= R[j]){
        A[k] = L[i];
        i = i + 1;
        cnt++;
    }
    else {
        A[k] = R[j];
        j = j + 1;
        cnt++;
    }
}
}

void MS(int *A,int left,int right){
    int mid;
    if(left+1 < right){
        mid = (left + right)/2;
        MS(A,left,mid);
        MS(A,mid,right);
        merge(A,right,left,mid);
    }
}
