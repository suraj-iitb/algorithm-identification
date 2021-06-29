#include<stdio.h>
#include<stdlib.h>

int cnt = 0;
void PrintArray(int a[], int n)
{
    for (int i = 0; i < n; i++){
        if (i != 0){
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}

void merge(int a[], int left, int right)
{
    if (left < right) {

    int middle = (left + right) / 2;
    if (left + 1 < right){
        merge(a, left, middle);
        merge(a, middle + 1, right);
    }
    

    int b[right - left + 1];
    
    int i = left;
    int j = middle + 1;
    int k;
    int state;
    
    for (k = 0; k <= right - left; k++){
        if (a[i] <= a[j]){
            b[k] = a[i++];
            cnt++;     
        }else {
            b[k] = a[j++];
            cnt++;
        }
        
        
        if (i > middle){
            state = 1;
            k++;
            break;
        }
        if (j > right){
            state = 0;
            k++;
            break;
        }      
    }

    for (; k <= right - left; k++){
        b[k] = state ? a[j++] : a[i++];
        cnt++;
    }    
    
    for (i = left; i <= right; i++){
        a[i] = b[i - left];
    }
    }

}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    merge(a, 0, n - 1);
    PrintArray(a, n);
    printf("%d\n", cnt);
}

