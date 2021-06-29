#include <stdio.h>
#define max 500000  
int L[max/2+2];
int R[max/2+2];
int c=0;
int merge(int S[], int n, int left, int mid, int right){
int i, j, k;      
int n1 = mid-left;
int n2 = right-mid;
for (i = 0; i < n1; i++)
L[i] = S[left+i];
for (i = 0; i < n2; i++)
R[i] = S[mid+i];
L[n1] = R[n2] = 2000000000;
i = j = 0;
for ( k = left; k < right; k++){
c++;
if ( L[i] <= R[j]){
S[k] = L[i]; 
i++;
}
else{
S[k] = R[j];
j++;
}
}
}
void mergeSort(int S[], int n, int left, int right){
int mid;
if (left+1<right){
mid = (left+right) / 2;
mergeSort(S,n, left,mid);
mergeSort(S, n,mid,right);
merge(S,n, left,mid,right);
}
}
int main(){
int S[max], n, i;
 
scanf("%d", &n);
for (i = 0; i < n; i++) 
scanf("%d", &S[i]); 
mergeSort(S, n, 0, n);
for (i = 0; i < n; i++){
if(i==0)
printf("%d", S[i]);
else 
printf(" %d", S[i]);
}

printf("\n");
 
printf("%d\n", c);
 
return 0;
}
