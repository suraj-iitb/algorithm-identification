#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void line_print(vector<int> &line)
{
   int line_size=line.size();
   for(int i=0;i<line_size;i++)
   {
       if(i!=0) cout << " ";
       cout << line.at(i);
   } 
   cout << endl;
}

int Bubble_sort(vector<int> &line)
{
    int line_size=line.size();
    int count=0;

    for(int i=0;i<line_size-1;i++) //sort終了点
    {
        for(int j=line_size-1;j>i;j--)
        {
            if(line.at(j)<line.at(j-1))
            {
                swap(line.at(j),line.at(j-1));
                count++;
            }
        }
    }
    return count;

}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin >> A.at(i);
    int count=Bubble_sort(A);
    line_print(A);
    cout << count << endl;
    return 0;


}
