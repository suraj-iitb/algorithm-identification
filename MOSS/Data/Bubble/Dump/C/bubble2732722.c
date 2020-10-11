#include <stdio.h>
int main() {
int n, i, j = 0, f = 1, x = 0, y;
int a[1000];
scanf("%d", &n);
for (i = 0;i < n;i++) {
scanf("%d", &a[i]);
}
while (f) {
f = 0;
for (i = n - 1;i > 0;i--) {
if (a[i] < a[i - 1]) {
y = a[i];
a[i] = a[i - 1];
a[i - 1] = y;
f = 1;
x++;
} } } for (i = 0;i < n;i++) {
if (i == n - 1) {
printf("%d\n%d\n", a[i], x);
} else {
printf("%d ", a[i]);
} } 
return 0;
}
