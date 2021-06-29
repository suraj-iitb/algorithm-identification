#include <iostream>                                             
#include <vector>                                               
using namespace std;                                            
                                                                
int main(void) {                                                
  int N;                                                        
  cin >> N;                                                     
  int x;                                                        
  vector<int> A;                                                
  for (int i=0; i<N; i++) {                                     
    cin >> x;                                                   
    A.push_back(x);                                             
  }                                                             
  int t, ans=0;                                                 
  for (int i=0; i<N; i++) {                                     
    int minj = i;                                               
    for (int j=i; j<N; j++) {                                   
      if (A[j]<A[minj]) {                                       
        minj = j;                                               
      }                                                         
    }                                                           
    t = A[i];                                                   
    A[i] = A[minj];                                             
    A[minj] = t;                                                
    if (i!=minj) {                                              
      ans++;                                                    
    }                                                           
  }                                                             
  for (int i=0; i<A.size(); i++) {                              
    cout << (i==0?"":" ") << A[i] << flush;                     
  }                                                             
  cout << endl <<  ans << endl;                                 
  return 0;                                                     
}                                                   
