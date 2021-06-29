void print(int A[], int N)
{
    int k;
    for (k = 0; k < N; k++) {
        if (k > 0) printf(" ");
        printf("%d", A[k]);
    }
    printf("\n");
}

int main (void)
{
   int i, N;
   int A[100];
   scanf("%d", &N);
   for (i = 0; i < N; i++) {
     scanf("%d", &A[i]);
   }
   print(A, N);
 
   for (i = 1; i < N; i++) {
     int v = A[i];
     int j = i - 1;
     while (j >= 0 && A[j] > v) {
       A[j+1] = A[j];
       j--;
     }
 
     A[j+1] = v;
     print(A, N);
   }
   return 0;
}
