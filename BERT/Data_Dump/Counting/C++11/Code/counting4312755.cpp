#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;
void countersort(int A[],int B[], int n){
    int c[10001];
    for(int i = 0; i < 10001 ; i++){
       c[i] = 0;
    } 
    for(int i = 0; i < n ; i++){
        c[A[i]]++;
    }

    for(int i = 1; i < 10001 ; i++){
       c[i] = c[i-1]+c[i]; 
    }

    for(int i = 0; i < n ; i++){
        B[c[A[n-i-1]]-1]=A[n-i-1];
        c[A[n-i-1]]--;
    }
}
int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n ; i++){
        scanf("%d",&A[i]); 
    }
    int B[n];
    countersort(A,B,n);
    for(int i=0; i<n; i++){
        if(i>=1)
            printf(" ");
        printf("%d",B[i]);
    }
    cout << endl;
}
