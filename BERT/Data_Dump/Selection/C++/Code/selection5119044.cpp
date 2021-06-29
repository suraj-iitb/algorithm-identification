#include<cstdio>
#include<algorithm>

using namespace std;

int selectionSort(int* a , int m){
    int count = 0;
    for(int x = 0; x < m ; x++){
        int min = x;
        for(int y = x ; y < m; y++ ){
            if(a[y] < a[min])min = y;

            }
            if(min != x){
                int aa = a[x];
                a[x] = a[min];
                a[min] = aa;
                count++;

            }

        }
    
    for(int i = 0; i < m-1 ; i++)printf("%d ",a[i]);
    printf("%d\n",a[m-1]);
    return count;
}

int main(){
   int n;
   scanf("%d",&n);
   int A[n];
   for(int i = 0;i < n; i++){
       scanf("%d",&A[i]);
   }
   printf("%d\n",selectionSort(A,n));

}
