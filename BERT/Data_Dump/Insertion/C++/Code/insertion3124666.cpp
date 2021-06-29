#include<stdio.h>
void out(int A[],int N){
	int i;
	for(i=0;i<N;i++){
		if(i>0)printf(" ");
		printf("%d",A[i]);}
	printf("\n");}
void insertionsort(int A[],int N){
	int i,j,v;
	for(i=1;i<N;i++){
		v=A[i];
		j=i-1;
		while(j>=0&&A[j]>v){
			A[j+1]=A[j];
			j--;}
		A[j+1]=v;
		out(A,N);}}
int main(){
	int A[100],N,i;
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d",&A[i]);
	out(A,N);
	insertionsort(A,N);
	return 0;}
