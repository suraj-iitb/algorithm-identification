#include<stdio.h>
#define N 100
int main(){
int i,j,lengh,key,A[N],mini,count=0,k;
 
scanf("%d",&lengh);
for(i=1;i<=lengh;i++){
scanf("%d",&A[i]);}
     
for(i=1;i<=lengh;i++){
    mini=i;
    for(j=i;j<=lengh;j++){
        if(A[j]<A[mini]){
        mini=j;
        }}         
    if(A[mini]<A[i]){
    key=A[i];
    A[i]=A[mini];
    A[mini]=key;
    count++;}}
    for(i=1;i<=lengh;i++){
        printf("%d",A[i]);
	if(i<lengh) printf(" ");}
    printf("\n%d\n",count);
    return 0;
}
