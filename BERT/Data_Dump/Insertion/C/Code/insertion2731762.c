#include <stdio.h>
int main(void) {
int n, i, j, k, x, p;
int a[1000];
scanf("%d", &n);
for (i = 0;i < n;i++) {
scanf("%d", &a[i]);
} for (p = 0;p < n;p++) {
if (p == n - 1) {
printf("%d", a[p]);
} else {
printf("%d ", a[p]);
}
} putchar('\n');
 for (i = 1; i < n;i++) {
j = i - 1;
k = a[i];
while (j >= 0 && a[j] > k) {
a[j + 1] = a[j];
j--;
a[j + 1] = k;
} for (p = 0;p < n;p++) {
if (p == n - 1) {
printf("%d", a[p]);
} else {
printf("%d ", a[p]);
} } putchar('\n');
}
return 0;
}
