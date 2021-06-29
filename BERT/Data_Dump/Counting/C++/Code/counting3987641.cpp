#include<bits/stdc++.h>
using namespace std;
int i,n,dato;
int sorted[2000000];
int main() {
 scanf("%d",&n);
 for(i=0;i<n;i++) {
   scanf("%d",sorted+i);
 } 
 sort(sorted, sorted+n);
 n--;
 for(i=0;i<n;i++) {
   printf("%d ",sorted[i]);
 } 
 printf("%d\n", sorted[i]);

 return 0;
}
