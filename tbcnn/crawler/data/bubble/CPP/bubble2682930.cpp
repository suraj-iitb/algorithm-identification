#include <stdio.h>
void print_array(int a[], int n){
int i = 0;
    for(i = 0; i<n-1; i++)
        printf("%d ",a[i]);
    printf("%d\n",a[i]);
}

void bubble_sort(int a[], int n){
    int res = 0;
    for(int i = 0; i<n; i++){
        for(int j=n-1; j>=i+1;j--){
            if(a[j] < a[j-1])
            {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                res++;
            }
        }
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
    bubble_sort(a,n);

    return 0;
}
