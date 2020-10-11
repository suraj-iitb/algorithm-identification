#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STR 100

int partition(int *A,char **B,int p,int r){	
	int x=A[r];
	int i=(p-1);
	int tmp;
	char *t=(char*)malloc(sizeof(char)*100);

	for(int j=p;j<r;j++){
		if(A[j]<=x){
			i++;
			tmp=A[i];
			A[i]=A[j];
			A[j]=tmp;
			strcpy(t,B[i]);
			strcpy(B[i],B[j]);
			strcpy(B[j],t);
		}
	}

	tmp=A[i+1];
	A[i+1]=A[r];
	A[r]=tmp;
	strcpy(t,B[i+1]);
	strcpy(B[i+1],B[r]);
	strcpy(B[r],t);
	return i+1;
}

void quickSort(int *A,char **B,int p,int r){
	int q;
	if(p<r){
		q=partition(A,B,p,r);
		quickSort(A,B,p,q-1);
		quickSort(A,B,q+1,r);
	}
}

int check_stable(int N,int *A,char **As,int *B,char **Bs){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(A[i]==B[j]){
				if(strcmp(As[i],Bs[j])!=0){
					return -1;
				}
				B[j]=0;
				break;
			}
		}
	}

	return 1;
}

int main(){
	int N;
	char **B,**B2;
	int *A,*A2;

	scanf("%d",&N);
	B=(char**)malloc(sizeof(char*)*N);
	A=(int*)malloc(sizeof(int)*N);
	B2=(char**)malloc(sizeof(char*)*N);
	A2=(int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++){
		B[i]=(char*)malloc(sizeof(char)*STR);
		B2[i]=(char*)malloc(sizeof(char)*STR);
		scanf("%s %d",B[i],&A[i]);
		A2[i]=A[i];
		strcpy(B2[i],B[i]);
	}
	
	quickSort(A,B,0,N-1);

	if(check_stable(N,A,B,A2,B2)==1){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}
		
	for(int i=0;i<N;i++){
		printf("%s %d\n",B[i],A[i]);
	}
	
	return 0;
}
