int binarySearch(int key, int n, int A[]){
  int left = 0;
  int right = n;
  while(left < right){
    int mid = (int)(left + right) / 2;
    if(A[mid] == key) return 1;
    else if (key < A[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
}

int main(){

  int i, n, q;
  scanf("%d", &n);
  int S[n];
  for(i=0; i<n; i++) scanf("%d", &S[i]);
  scanf("%d", &q);
  int T[n];
  for(i=0; i<n; i++) scanf("%d", &T[i]);

  int anw = 0;

  for(i=0; i<q; i++){
    if(binarySearch(T[i], n, S)) anw++;
  }

  printf("%d\n", anw);
  
  return 0;
}
