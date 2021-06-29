#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin >> n;
   vector<int> p(n);
   for(int i = 0;i<n;i++){
       cin >> p.at(i);
   }

   for(int j = 0; j < n - 1; j++){
            cout << p.at(j) << " ";
        }

        cout << p.at(n-1) << endl;
   int v = 0;
   int j = 0;
   for(int i = 1; i < n; i++){
        v = p.at(i);
        j = i - 1;
        while(j >= 0 && p.at(j) > v){
            p.at(j+1) = p.at(j);
            j--;
        }
        p.at(j+1) = v;
        for(int j = 0; j < n - 1; j++){
            cout << p.at(j) << " ";
        }

        cout << p.at(n-1) << endl;
   }
}


