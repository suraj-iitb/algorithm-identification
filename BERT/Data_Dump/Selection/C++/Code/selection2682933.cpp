#include <stdio.h>
void print_array(int a[], int n){
int i = 0;
    for(i = 0; i<n-1; i++)
        printf("%d ",a[i]);
    printf("%d\n",a[i]);
}

void selection_sort(int a[], int n){
    int res = 0;
    for(int i = 0; i<n; i++){
        int mini = i;
        for(int j=i; j<n;j++){
            if(a[j] < a[mini]) mini = j;
        }
        //swap
        int temp = a[i];
        a[i] = a[mini];
        a[mini] = temp;
        if(mini!=i)
            res++;
    }
    print_array(a,n);
    printf("%d\n",res);
}
//bubble sort
int main()
{
    int n = 0;
    scanf("%d",&n);
    int a[n+1];
    for(int i = 0; i<n; i++){
        scanf("%d",&a[i]);
    }
    //print_array(a,n);
    selection_sort(a,n);

    return 0;
}

