#include<stdio.h>
#define INFINITY 2000000000

int count;

int merge(int s[], int left, int mid, int right, int n){

    int n1, n2, i, j, k;
    int L[300000];
    int R[300000];

    n1 = mid - left;
    n2 = right - mid;

    for(i = 0; i < n1; i++) L[i] = s[left + i];
    for(i = 0; i < n2; i++) R[i] = s[mid + i];

    L[n1] = INFINITY;
    R[n2] = INFINITY;
    i = 0;
    j = 0;

    for(k = left; k < right; k++){

        count++;

        if(L[i] <= R[j]){

            s[k] = L[i];
            i++;

        }
        else{

            s[k] = R[j];
            j++;

       }
    }
}
int mergeSort(int s[], int left, int right){

    int mid;
    int n = right;

    if(left+1 < right){

        mid = (left + right) /2;
        mergeSort(s, left, mid);
        mergeSort(s, mid, right);
        merge(s, left, mid ,right, n);

    }

}
int main()
{
    int i, n;
    int s[500000];
    count = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++){

        scanf("%d", &s[i]);
    }

    mergeSort(s, 0, n);

    for(i = 0; i < n; i++){

        if(i > 0) printf(" ");

        printf("%d", s[i]);
    }
    printf("\n");

    printf("%d\n", count);

    return 0;
}
