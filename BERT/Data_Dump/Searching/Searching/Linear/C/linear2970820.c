#include <stdio.h>
int LinearSearch(int s[], int n, int key){
  int i = 0;
  s[n] = key;
  while(s[i] != key){
i++; }
  return i != n;
}
int main(){
  int i, n, p, key, count = 0;
  int s[10000];
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%d", &s[i]);
  }
  scanf("%d", &p);
  for (i = 0; i < p; i++){
    scanf("%d", &key);
    if (LinearSearch(s, n, key) == 1){
count++;
}
}
  printf("%d\n", count);
return 0; }
