#include<iostream>
#include<cstdio>

using namespace std;
static const int N = 100;

void inputArray(int a[], int n){
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
}

void printArray(int a[], int n){
    int k = 0;
    while(1){
        if(k==n-1) break;
        else{
            printf("%d ", a[k]);
        }
        k++;
    }
    printf("%d\n", a[n-1]);
}

int bubbleSort(int a[], int n){
    int flag = 1,v,count = 0;
    while(flag){
        flag = 0;
        for (int j = n-1; j >= 1; j--)
        {
            if (a[j]<a[j-1]){
                v = a[j-1];
                a[j-1] = a[j];
                a[j] = v;
                flag = 1;
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n,m;
    int A[N];
    cin >> n;
    inputArray(A,n);
    m = bubbleSort(A,n);
    printArray(A,n);
    printf("%d\n", m);

    return 0;
}
