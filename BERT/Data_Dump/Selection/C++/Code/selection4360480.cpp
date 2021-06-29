#include <stdio.h>
void selectionSort(int *a,int n,int *count){
    int min,t;
    for(int i=0;i<n;i++){
        min = i;
        for(int j=i;j<n;j++){
            if(a[min]>a[j]){
                min = j;
            }
        }
        t = a[i];a[i] = a[min];a[min] = t;
        if(i != min) *count = *count + 1;
    }
};
void show(int *a,int n){
    for(int i=0;i<n;i++){
        if(i != n-1){
            printf("%d ",a[i]);
        }else
        {
            printf("%d\n",a[i]);
        }
        
    }
}
int main(){
    int A[100];
    int n;
    int c = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&A[i]);
    selectionSort(A,n,&c);
    show(A,n);
    printf("%d\n",c);

}
