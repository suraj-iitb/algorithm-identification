#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dump(int *A, int N)
{
	int i;

    for (i=0; i<N; i++){
		if (i)
			printf(" ");
        printf("%d", A[i]);
	}
    printf("\n");
}
void insertionSort(int *A, int N) // N??????????´??????????0-?????????????????????A
{
    int i,j,v;

    //printf("start sorting\n");
    for(i=1; i<N; i++){// ??? 1 ?????? N-1 ?????§
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
		dump(A, N);
    }
    //printf("end of sort\n");
}

char Arg[1024];
int main(void)
{
    int i,j,k,N, *Array; char work[5];

	gets(work);
    N=atoi(work);
    //printf("Number of element %d\n", N);
    Array=malloc(N*sizeof(int));
    if (Array==NULL)
        return -1;
    gets(Arg);
	//printf("-|%s|-\n", Arg);
    for(i=j=k=0; Arg[j]; ){
        for (j=i; Arg[j]!=' ' && Arg[j]; j++);
        if (i!=j){
            strncpy(work, &Arg[i], j-i);
			work[j-i]=0;
			//printf("%d|%s|%d\n", i, work, j);
            Array[k++]=atoi(work);
            i=j+1;
        }
    }
    //printf("array input done\n");
	dump(Array, N);
    insertionSort(Array, N);
    free(Array);
}
