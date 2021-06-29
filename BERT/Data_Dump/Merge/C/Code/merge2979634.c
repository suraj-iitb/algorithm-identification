#include <stdio.h>
void mergeSort(int A[],int,int );
void merge(int A[],int,int,int );
int Mid;
int c=0;
int L[500000],R[500000];
int main(){
        int A[1000000];
        int n,i;

        scanf("%d",&n);
        for(i=0; i<n; i++) {
                scanf("%d",&A[i]);
        }

        mergeSort(A,0,n);
        for(i=0; i<n; i++) {
                printf("%d",A[i]);
                if(i<n-1) printf(" ");
        }
        printf("\n");
        printf("%d\n",c);


        return 0;
}
void mergeSort(int A[],int Left,int Right){

        if(Left+1<Right) {
                int Mid=(Left+Right)/2;
                mergeSort(A,Left,Mid);
                mergeSort(A,Mid,Right);
                merge(A,Left,Mid,Right);

        }
}

void merge(int A[],int Left,int Mid,int Right){
        int i,j,l1,l2,k;
        l1=Mid-Left;
        l2=Right-Mid;

        for(i=0; i<l1; i++) {
                L[i]=A[Left+i];
        }
        for(j=0; j<l2; j++) {
                R[j]=A[Mid+j];
        }
        L[l1]=1000000000;
        R[l2]=1000000000;
        i=0;
        j=0;
        for(k=Left; k<Right; k++)
                if(L[i]<=R[j]) {
                        A[k]=L[i];
                        i++;
                        c++;

                }
                else{
                        A[k]=R[j];
                        j++;
                        c++;

                }
}

