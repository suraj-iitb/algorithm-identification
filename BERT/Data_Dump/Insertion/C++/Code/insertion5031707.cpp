#include <iostream>
int main()
{
    int cnt;
    std::cin >> cnt;
    int values[100];
    for(int i=0;i< cnt;i++)
        std::cin >> values[i];
    int tmp;
    int j;
    for (int i=0;i<cnt;i++)
    {
        tmp = values[i];
        j = i - 1;
        while ((j>=0)&&(values[j]>tmp))
        {
            values[j + 1] = values[j];
            j--;
        }
        values[j + 1] = tmp;

        for (int t=0;t<cnt;t++)
        {
            if(t!=0)
                std::cout << " ";

            std::cout << values[t];
        }
        std::cout  << std::endl;
    }

}
