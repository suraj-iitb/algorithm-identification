#include<stdio.h>

int A[500000],count=0;

void Merge(int l,int m,int r){

int n1=m-l,n2=r-m,i,j,k;
int L[n1],R[n2];
for(i=0;i<n1;i++){
L[i]=A[l+i];
}
for(i=0;i<n2;i++){
R[i]=A[m+i];
}
L[n1]=1000000001;
R[n2]=1000000001;
for(i=0,j=0,k=l;k<r;k++){
if(L[i]<=R[j]){
A[k]=L[i];
i++;
}
else {
A[k]=R[j];
j++;
}
count++;
}

}

void Merge_Sort(int l,int r){
int m;
if(l+1<r){
m=(l+r)/2;
Merge_Sort(l,m);
Merge_Sort(m,r);
Merge(l,m,r);
}
}

int main(){
int n,i;
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d",&A[i]);

Merge_Sort(0,n);
for(i=0;i<n;i++){
printf("%d",A[i]);
if(i!=n-1)printf(" ");
}
printf("\n%d\n",count);

return 0;
}
