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
int  BubbleSort(vector<int> &A)
{
    int count = 0;
    for(int i = 0; i < A.size(); i++){
        for(int j = A.size()-1; j >= i+1; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                count++;
            }
        }
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
    int Count = BubbleSort(A);
    Output(A);
    std::cout << Count << std::endl;
    return 0;
}
