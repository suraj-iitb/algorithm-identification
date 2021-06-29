#include <iostream>
#include <vector>
#include <map>
#include <limits>
using namespace std;

unsigned long long sum = 0;
void out(std::string msg, int* a, int left, int right)
{
    cout << msg << "[" << left << ":" << right  << "): ";
    for(int i=left; i<right; i++) cout << a[i] << " ";
    cout << endl;
}
void merge(int* a, int left, int mid, int right)
{
    //out("merge ", a, left, right);
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1], R[n2+1];
    for(int i=0; i<n1; i++){
        L[i] = a[left+i];
    } 
    for(int i=0; i<n2; i++){
        R[i] = a[mid+i];
    }
    //out("L", L, 0, n1);
    //out("R", R, 0, n2);
    L[n1] = 1000000001; /*std::numeric_limits<int>::infinity();*/
    R[n2] = 1000000001; /*std::numeric_limits<int>::infinity();*/
    int i=0, j=0;
    for(int k=left; k<right; k++){
        if(L[i] <= R[j]){
            a[k] = L[i]; i++;
        }else{
            a[k] = R[j]; j++;
        }
        sum++;
    }
    //out("merged", a, left, right);
}
void mergeSort(int* a, int left, int right)
{
    //out("mergeSort", a, left, right);
    if(left+1 >= right) return;
    int mid = (left+right)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int left = 0;
    int right = n;
    mergeSort(a, left, right);

    for(int i=0; i<n; i++){
        cout << a[i];
        if(i != n-1) cout << " ";
        else cout << endl;
    }
    cout << sum << endl;
}
