void
p(int arr[], int n)
{
  int i;
  printf("%d", arr[0]);
  for (i=1; i<n; i++) {
    printf(" %d", arr[i]);
  }
  printf("\n");
}

int
main()
{
  int n, i;
  int arr[100];

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  for (i=0; i<n; i++) {
    int key = arr[i];
    int j = i - 1;
    while ((j >= 0) && (arr[j] > key)) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
    p(arr, n);
  }
}

