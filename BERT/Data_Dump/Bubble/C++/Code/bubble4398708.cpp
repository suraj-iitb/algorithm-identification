#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0;i<n;i++){
       cin >> a.at(i);
   }

   bool flag = true;
   int cnt = 0;
   int tmp = 0;
   while(flag){
       flag = false;
       for(int j = n-1;j >= 1;j--){
           if(a.at(j) < a.at(j-1)){
               swap(a.at(j-1),a.at(j));
               cnt++;
               flag = true;
           }
       }
   }

   for(int i = 0;i < n;i++){
       if(i > 0) cout << " ";
       cout << a.at(i);
   }
   cout << endl;

   cout << cnt << endl;

}
