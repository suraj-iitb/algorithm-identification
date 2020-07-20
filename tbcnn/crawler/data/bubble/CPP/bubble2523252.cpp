#include <iostream>                                            
using namespace std;                                           
                                                               
int main() {                                                   
  int N;                                                       
  cin >> N;                                                    
  int A[N];                                                    
  for (int i=0; i<N; i++) {                                    
    cin >> A[i];                                               
  }                                                            
  bool f = true;                                               
  int ans = 0;                                                 
  while (f) {                                                  
    f = false;                                                 
    for (int j=N-1; j>=1; j--) {                               
      if (A[j]<A[j-1]) {                                       
        int v = A[j-1];                                        
        A[j-1] = A[j];                                         
        A[j] = v;                                              
        f = true;                                              
        ans++;                                                 
      }                                                        
    }                                                          
  }                                                            
  for (int i=0; i<N; i++) {                                    
    cout << (i==0?"":" ") << A[i] << flush;                    
  }                                                            
  cout << endl;                                                
  cout << ans << endl;                                         
  return 0;                                                    
}                      
