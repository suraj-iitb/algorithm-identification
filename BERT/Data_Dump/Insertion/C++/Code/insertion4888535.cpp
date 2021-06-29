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

void Insertion_sort(vector<int> &line)
{
    int line_size=line.size();
    for(int i=1;i<line_size;i++)
    {
        int now_at=line.at(i);
        int j=i-1;
        while(j>=0 && line.at(j)>now_at)
        {
            line.at(j+1) = line.at(j);
            j--;
        }
        line.at(j+1)=now_at;
        line_print(line);
    }

}
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin >> A.at(i);

    line_print(A);
    Insertion_sort(A);

    return 0;
}

