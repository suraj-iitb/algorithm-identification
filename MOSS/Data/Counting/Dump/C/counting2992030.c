#include <stdio.h>
#define  M   2000001

void counting_sort(int a[], int b[], int n);
void print_data(int data[], int array_length);

int work_data[M-1];

int count[M+1];

int main(int argc, char **argv)
{
  int i,N,src_data[M];
    scanf("%d",&N);
    for(i=0;i<N;i++){
      scanf("%d",&src_data[i]);
    }
    counting_sort(src_data, work_data, N);
    print_data(work_data, N);
    return 0;
}

void counting_sort(int a[], int b[], int n)
{
    int  i;
    for (i = 0; i <= M; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[a[i]]++;

    for (i = 0; i < M; i++) {
        count[i+1] += count[i];
    }

    for (i = n - 1; i >= 0; i--) {
        b[--count[a[i]]] = a[i];
    }
}

void print_data(int data[], int array_length)
{
    int i;
    for (i = 0; i < array_length-1; i++) {
        printf("%d ", data[i]);
    }
    printf("%d",data[array_length-1]);
    printf("\n");
}
