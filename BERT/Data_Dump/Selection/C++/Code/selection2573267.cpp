#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void Output(const vector<int>& List)
{
    for(std::size_t i = 0; i < List.size(); ++i){
        if(i) std::cout << " ";
        std::cout << List[i];
    }
    std::cout << std::endl;
}
int selectionSort(vector<int>& A){
    int count = 0;
    for(int i = 0; i < A.size(); i++){
        int minj = i;
        for(int j = i; j < A.size(); j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        count += i != minj;
        swap(A[i], A[minj]);
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int Count = selectionSort(A);
    Output(A);
    std::cout << Count << std::endl;
    return 0;
}
