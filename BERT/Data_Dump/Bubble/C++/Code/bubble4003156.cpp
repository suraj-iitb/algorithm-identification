#include <bits/stdc++.h>
using namespace std;

//vector<int>のサイズnと要素の入力
vector<int> input_vector()
{
    int n;
    scanf("%d", &n);
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vec[i]);
    }
    return vec;
}

//第１引数がvectorで第２引数がサイズ
void print_vector(vector<int> &vec, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i != N - 1)
        {
            printf("%d ", vec[i]);
        }
        else
        {
            printf("%d\n", vec[i]);
        }
    }
}

//bubble_sort カウント数あり
int bubble_sort(vector<int> &A, int n)
{
    bool flag = 1;
    int m;         //変数交換用
    int i = 1;     //未ソート部分先頭アドレス
    int count = 0; //反転数
    for (i; flag; i++)
    {
        flag = 0;
        for (int j = n - 1; j >= i; j--)
        {
            if (A[j - 1] > A[j])
            {
                m = A[j];
                A[j] = A[j - 1];
                A[j - 1] = m;
                flag = 1;
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<int> A=input_vector();
    int n=A.size();
    int count=bubble_sort(A,n);
    print_vector(A,n);
    printf("%d\n", count);
}




