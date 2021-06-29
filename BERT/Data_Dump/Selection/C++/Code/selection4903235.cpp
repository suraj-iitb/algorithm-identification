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

int selectionSort(vector<int> &line)
{
    int line_len=line.size();
    int count=0;
    for(int i=0;i<line_len;i++)
    {
        int m_min=i;
        int taihi=line.at(i);
        for(int j=i+1;j<line_len;j++)
        {
            if(line.at(m_min)>line.at(j))
            {
                m_min=j;
            } 
        } 

        if(m_min!=i)
        {
            line.at(i)=line.at(m_min);
            line.at(m_min)=taihi;
            count++;
        }
    }
    return count;
}

int main()
{
    int N;
    cin >> N;
    vector<int> line(N);
    for(int i=0;i<N;i++) cin >> line.at(i);
    int ch_count=selectionSort(line);
    line_print(line);
    cout << ch_count << endl;
    return 0;
}
