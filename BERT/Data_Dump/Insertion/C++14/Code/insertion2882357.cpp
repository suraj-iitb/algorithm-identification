#include <iostream>
#include <vector>
using namespace std;

void print_vec(vector<int> &vec){
    for(int i=0; i<vec.size(); i++)
        cout << vec[i] << (i==vec.size()-1? "\n" : " ");
}

int main(){
    int N; cin >> N;
    vector<int> vec(N);
    
    for(auto &v: vec)
        cin >> v;
    
    print_vec(vec);
    for(int i=1; i<N; i++){
        int key = vec[i];
        int j = i-1;
        while(j>=0 && vec[j]>key){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
        print_vec(vec);
    }
    return 0;
}

