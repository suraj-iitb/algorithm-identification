#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

void print(int A[], int N){
    for(int i=0;i<N;i++){
        if(i>0)printf(" ");
        printf("%d",A[i]); 
    }
    printf("\n");
}

void insert(int A[], int N){
    int v,j;
    for(int i=1;i<N;i++){
        v = A[i];
        j = i - 1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        print(A, N);
    }
}
int main(){
   int N;
   int A[100];

   cin >> N;
   for(int i = 0;i<N;i++) cin >> A[i];
   print(A, N);
   insert(A, N);
 return 0;

}

