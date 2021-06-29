#include<stdio.h>
 
#define N1 500000
#define N2 1000000000
            
int Merge(int S[], int, int, int);
int Merge_sort(int S[], int, int);
 
int sum=0;
 
 
 
int main(){
 
int S[N1];
int i, n;
 
scanf("%d",&n);
 
for(i = 0; i < n; i++){
scanf("%d",&S[i]);
}
 
Merge_sort(S, 0, n);
 
 
for(i = 0; i<n; i++){
printf("%d",S[i]);
 
if(i<n-1) printf(" ");
 
}
printf("\n%d\n",sum);
return 0;
 
}
 
int Merge(int S[], int left, int mid, int right){
 
int n1 = mid - left;
int n2 = right - mid;
int L[n1], R[n2];
int i, j, k;
 
for(i = 0; i < n1; i++){
L[i] = S[left + i];
}
 
for(i = 0; i < n2; i++){
R[i] = S[mid + i];
}
 
L[n1] = N2;
R[n2] = N2;
 
i=0;
j=0;
 
for(k=left; k < right; k++){
 
if(L[i] <= R[j]){
S[k] = L[i];
i++;
}
 
else {
S[k] = R[j];
j++;
}
sum++;
}
 
}
 
int Merge_sort(int S[], int left, int right){
 
int mid;
 
if(left + 1 < right){
 mid = (left + right)/2;
        Merge_sort(S,left,mid);
        Merge_sort(S,mid,right);
        Merge(S,left,mid,right);
}
 
}
