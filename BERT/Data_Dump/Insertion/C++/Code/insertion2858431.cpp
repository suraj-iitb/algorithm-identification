#include <iostream>
#include <vector>

#define REP(i,s,N) for(int i=s; i<N; ++i)

/// print vector
template<typename U>
inline void print(U u) {
        if (u.size() == 0) return;
        std::cout << u[0];
        for (int i=1; i<u.size(); ++i) std::cout << " " << u[i];
        std::cout << std::endl;
}

using namespace std;

int main(){
        int N;
        cin >> N;

        vector<int> x(N,0);
        REP(i,0,N) {
                cin >> x[i]; 
        }   
        // insertion sort
        print(x);
        REP(i,1,N) {
                int key = x[i];
                int j = i-1;
                while (j >= 0 && x[j] > key) {
                        x[j+1] = x[j];
                        j--;
                }
                x[j+1] = key;
                print(x);
        }
        return 0;
}

