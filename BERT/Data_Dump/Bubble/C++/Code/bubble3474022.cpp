#include<iostream>
#include<memory>
#include <vector>
#include <string>
#include<sstream>

using namespace std;

int bubblesort(vector<int> &vec){
    int counts_swap{0};
    int flag = 1;
    for (int i = 0; flag; i++){
        flag = 0;
        for (int j = vec.size()-1; j >= i + 1; j--){
            if (vec[j-1] > vec[j]){
                swap(vec[j], vec[j-1]);
                counts_swap++;
                flag = 1;
            }
        }
    }
    return counts_swap;
}


int main(){
    int N, i, j;
    cin >> N;
    vector<int> vec(N);
    int val;
    for(i = 0; i < N; i++){
        cin >> val;
        vec[i] = val;
    }

    int c;
    c = bubblesort(vec);
    /*
    for (i = 0; i < vec.size(); i++){
        if (i > 0 ) cout << " ";
        cout << vec[i];
    }
    */
    for(int i=0;i<N;i++) cout<<vec[i]<<" \n"[i==N-1];
    cout << c << endl; 
    /*
    while(cin >> val){
        vec[]
    }
    */

}
