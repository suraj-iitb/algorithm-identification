#include <iostream>

using namespace std;

int bsort(int a[],int n){
    int sw=0;
    bool flag=1;
    while(flag){
            flag=0;
        for(int i=n-1;i>0;i--){
            if(a[i]<a[i-1]){
                swap(a[i],a[i-1]);
                flag=1;
                sw++;
            }
        }
    }
    return sw;
}

int main()
{
   int n;
   cin >>n;
   int a[n];
   for(int i=0;i<n;i++){
       cin >> a[i];
   }
   int co;
   co=bsort(a,n);
   for(int i=0;i<n;i++){
        if(i)cout << " ";
        cout << a[i];
   }
   cout << endl;
   cout << co<< endl;
    return 0;
}

