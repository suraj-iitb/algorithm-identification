#include <stdio.h>
using namespace std;
void insertionSort(int[],int);
void callarr(int[],int);
int main()
{   
    int N;
    int arr[110];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,N);
    return 0;
}
void insertionSort(int arr[],int N)
{   
    callarr(arr,N);
    for(int i=1;i<N;i++){
        int v=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>v){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=v;
        callarr(arr,N);
    }
}
void callarr(int arr[],int N){
    for(int k=0;k<N-1;k++) printf("%d ",arr[k]);
        printf("%d\n",arr[N-1]);

}
