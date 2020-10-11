#include<stdio.h>
void bubbleSort(int A[],int N){
int flag=1;
int f,j,e;
int c=0;
while(flag){
flag=0;
for(j=N-1;j>0;j--){
if(A[j]<A[j-1]){
f=A[j];
A[j]=A[j-1];
A[j-1]=f;  
flag=1;
c++; 
        }
     }
   }
for(e=0;e<N;e++){
printf("%d",A[e]);
if(e==N-1){
printf("\n");
}else{
printf(" ");
}
}
printf("%d\n",c);
}

int main(){
int a,b[100],d;
scanf("%d",&a);
for(d=0;d<a;d++){
scanf("%d",&b[d]);
} 
bubbleSort(b,a);
}








