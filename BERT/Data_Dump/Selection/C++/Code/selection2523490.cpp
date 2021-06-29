#include <iostream>                                             
#include <cstdio>                                               
using namespace std;                                            
                                                                
int main() {                                                    
  int N;                                                        
  cin >> N;                                                     
  int A[N];                                                     
  for (int i=0; i<N; i++) {                                     
    cin >> A[i];                                                
  }                                                             
  int ans = 0;                                                  
  for (int i=0; i<N; i++) {                                     
    int minj = i;                                               
    for (int j=i; j<N; j++) {                                   
      if (A[j]<A[minj]) {                                       
        minj = j;                                               
      }                                                         
    }                                                           
    int v = A[i];                                               
    A[i] = A[minj];                                             
    A[minj] = v;                                                
    if (i!=minj) {                                              
      ans++;                                                    
    }                                                           
  }                                                             
  for (int i=0; i<N; i++) {                                     
    cout << (i==0?"":" ") << A[i] << flush;                     
  }                                                             
  printf("\n");                                                 
  cout << ans << endl;                                          
  return 0;                                                     
}                                                               
                                                                
             
