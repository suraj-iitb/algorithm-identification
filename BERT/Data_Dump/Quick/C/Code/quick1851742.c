#include <stdio.h>
#include <stdlib.h>
#define N 100000
#define MAX 1000000005

typedef struct {
char mark;
int number;
} Card;

Card L[N/2+1],R[N/2+1];
void merge(Card A[],int left,int mid, int right){
int i,j,k,n1,n2;

n1 = mid - left;
n2 = right - mid;
for(i=0; i<n1; i++) L[i] = A[left + i];
for(i=0; i<n2; i++) R[i] = A[mid + i];
L[n1].number = MAX;
R[n2].number = MAX;
i = 0;
j = 0;
for(k=left; k<right; k++){
if(L[i].number <= R[j].number){
A[k] = L[i];
i = i + 1;
}
else{
A[k] = R[j];
j = j + 1;
}
}
}


void mergeSort(Card A[],int left,int right){
int mid;
if(left+1 < right){
mid = (left + right) / 2;
mergeSort(A,left,mid);
mergeSort(A,mid,right);
merge(A,left,mid,right);
}
}

int partition(Card A[],int p, int r){
int i,j;
Card x,kari;
x = A[r];
i = p - 1;
for(j=p; j<r; j++){
if(A[j].number <= x.number){
i++;
kari = A[i];
A[i] = A[j];
A[j] = kari;
}
}
kari = A[i+1];
A[i+1] = A[r];
A[r] = kari;

return i+1;
}

void quickSort(Card A[],int p, int r){
int q;
if(p < r){
q = partition(A,p,r);
quickSort(A,p,q-1);
quickSort(A,q+1,r);
}
}

int main(){
int i,num,check=0,suji;
char moji[5];
Card M[N],Q[N];
scanf("%d",&num);
for(i=0; i<num; i++){
scanf("%s""%d",moji,&suji);
M[i].mark = moji[0];
Q[i].mark = moji[0];
M[i].number = suji;
Q[i].number = suji;
}

mergeSort(M,0,num);
quickSort(Q,0,num-1);

for(i=0; i<num; i++){
if(M[i].mark != Q[i].mark) check=1;
}
if(check == 0) printf("Stable\n");
else printf("Not stable\n");
for(i=0; i<num; i++) printf("%c %d\n",Q[i].mark,Q[i].number);

return 0;
}
