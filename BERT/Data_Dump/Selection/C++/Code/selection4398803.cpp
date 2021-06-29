#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0;i<n;i++){
       cin >> a.at(i);
   }

   int minj = 0;
   int cnt = 0;
   for(int i = 0; i < n; i++){
       minj = i;
       for(int j = i; j < n; j++){
           if(a.at(j) < a.at(minj)){
               minj = j;
               
           }
       }
       if(a.at(i) != a.at(minj)){
           swap(a.at(i),a.at(minj));
           cnt++;
       }
   }

   for(int i = 0;i < n;i++){
       if(i > 0) cout << " ";
       cout << a.at(i);
   }

   cout << endl;
   cout << cnt << endl;
}
