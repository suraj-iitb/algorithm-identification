#include <iostream>
#include <vector>

using namespace std;

int selection_sort(vector<int> &vec){
    int x = 0;
    for(int i=0; i<vec.size(); i++){
        int minj = i;
        for(int j=i; j<vec.size(); j++){
            if(vec[j] < vec[minj])
                minj = j;
        }
        if(minj != i)
            x++;
        swap(vec[minj], vec[i]);
    }
    return x;
}

int main(){
    int N; cin >> N;
    
    vector<int> vec(N);
    for(auto &v: vec)
        cin >> v;
    
    int x = selection_sort(vec);
    
    for(int i=0; i<N; i++)
        cout << vec[i] << (i==N-1? "\n": " ");
    cout << x << endl;
    
    return 0;
}

