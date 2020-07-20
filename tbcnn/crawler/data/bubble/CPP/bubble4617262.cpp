#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin >> A[i];
    bool ok = 1;
    int count = 0;
  	int i = 0;

    for(int i=0;ok;i++){
      ok = 0;
        for(int j=n-1;j>i;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                ok = 1;
                count++;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(i>0) cout << " ";
        cout << A[i];
    }
    cout << endl << count << endl;
}
