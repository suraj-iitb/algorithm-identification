#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    //printf("%d",n);
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    for(int foc = 0; foc < n; foc++){
        int key = A[foc];
        int j = foc-1;
        while( j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        //printf("debug\n");
        for(int i=0; i<n; i++){
            printf("%d", A[i]);
            if(i!=n-1)printf(" ");
        }
        printf("\n");
    }
}
