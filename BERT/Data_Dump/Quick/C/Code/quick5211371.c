#include<stdio.h>
#define MAX 30000000

typedef struct 
{
    char moji;

    int suuji;
    /* data */
}card;

card O[100000/2 + 2],P[100000/2 + 2];



void merge_sort(card *,int,int);
void merge(card*,int,int,int);

void quick_sort(card *,int,int,int);

int partition(card *,int,int,int);


int main(){

    int n,i,x;

    char y;

    char num[20];

    int stable = 1;

    card X[100000],Y[100000];


    scanf("%d",&n);

    for(i = 0;i < n;i++){

        scanf("%s %d",num,&x);

        X[i].moji = Y[i].moji = num[0];

        X[i].suuji = Y[i].suuji = x;
    }

    merge_sort(X,0,n);

    quick_sort(Y,n,0,n-1);

    for(i = 0;i < n;i++){

        if(X[i].moji != Y[i].moji){

            stable = 0;
        }
    }

        if(stable == 1){

            printf("Stable\n");
        }

        else{

            printf("Not stable\n");

        }

    for(i = 0;i < n;i++){

        printf("%c %d\n",Y[i].moji,Y[i].suuji);
    }

    /*printf("     \n");


    for(i = 0;i < n;i++){

        printf("%c %d\n",X[i].moji,X[i].suuji);
    }*/

    return 0;



}



void merge_sort(card X[],int left,int right){

    int mid;
    
  if (left + 1 < right) {
    mid = (left + right)/2; 
    merge_sort(X, left, mid);  
    merge_sort(X, mid, right); 

     //printf("test\n");

    merge(X,mid,left,right);
    
  }
}

void merge(card A[],int mid,int left,int right){

    int B[500000],j,i,k,n1,n2;

    //int L[500000],R[500000];

    n1 = mid - left;

    n2 = right - mid;

    for(i = 0;i < n1;i++){

        O[i] = A[left + i];
    }

    for(i = 0;i < n2;i++){

        P[i] = A[mid + i];

    }

        O[n1].suuji = P[n2].suuji = MAX;
    i = j = 0;

    for(k = left;k < right;k++){

        if(O[i].suuji <= P[j].suuji){

            A[k] = O[i++];
        }
        else{
            A[k] = P[j++];
        }
    }
    

}
void quick_sort(card B[],int n,int p,int r){

    int q;

    if(p < r){
        q = partition(B,n,p,r);
        quick_sort(B,n,p,q - 1);
        quick_sort(B,n,q+1,r);
    }


}

int partition(card A[],int n,int p,int r){

    int i,j;

    card t,x;

    x = A[r];

    i = p - 1;

    for(j = p;j < r;j++){

        if(A[j].suuji <= x.suuji){
            i++;

            t = A[i];

            A[i] = A[j];

            A[j] = t;
        }

    }
    t = A[i+1];

    A[i + 1] = A[r];
    
    A[r] = t;

    return i + 1; 
}
