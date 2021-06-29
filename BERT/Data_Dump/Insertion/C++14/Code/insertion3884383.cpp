#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
static const int MAX = 100;

int main(){
    int A[MAX], n;

    cin >> n;
    rep(i, n) cin >> A[i];
  
  	rep(k, n){
        if(k > 0) printf(" ");
    	printf("%d", A[k]);
    }
    printf("\n");

    int j , v;
    
    rep2(i, 1, n){
        v = A[i];
        j = i - 1;

        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = v;
        
        rep(k, n){
            if(k > 0) printf(" ");
          	printf("%d", A[k]);
        }
      	printf("\n");
    }
}
