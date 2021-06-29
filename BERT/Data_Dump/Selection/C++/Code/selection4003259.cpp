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

//交換回数あり任意の要素
int selection_sort(vector<int> &vec)
{
    int n = vec.size();
    int m;    //変数交換用
    int minj; //暫定的な最小値アドレス
    int count = 0;
    for (int j = 0; j < n - 1; j++)
    { //jは未ソート部分の先頭アドレス
        minj = j;
        for (int i = j + 1; i < n; i++)
        {
            if (vec[i] < vec[minj])
            {
                minj = i;
            }
        }
        if(minj!=j){
        m = vec[minj];
        vec[minj] = vec[j];
        vec[j] = m;
        count++;
        }
    }
    return count;
}

//第１引数がvectorで第２引数がサイズのvector出力
void print_vector(vector<int> &vec)
{
    int N=vec.size();
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

int main(){
    vector<int> A=input_vector();
    int count=selection_sort(A);
    print_vector(A);
    cout<<count<<endl;
}

