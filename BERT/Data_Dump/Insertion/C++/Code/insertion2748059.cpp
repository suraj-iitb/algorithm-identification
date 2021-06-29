#include <iostream>


using namespace std;

int main(){
 int n,i,j,temp;
 cin >> n;
 int a[n];
 for (i=0;i<n;++i) {
   cin >> a[i];
 }

 for (i=0;i<n;++i) {
   temp=a[i];
   for (j=i-1;j>-1;--j) {
     if (a[j]>temp) {
       a[j+1]=a[j];
     } else {
       break;
     }
   }
   a[j+1]=temp;
   for (j=0;j<n;++j) {
     cout << a[j];
     if (j<n-1) {
       cout << " ";
     } else {
       cout << endl;
     }
   }
 }
 return 0;
}

