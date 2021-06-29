#include <iostream>
int main()
{
    int cnt;
    std::cin >> cnt;
    int  values[100];
    for (int i = 0; i < cnt; i++)
        std::cin >> values[i];

    int tmp;
    bool flag = true;
    int sum = 0;
    while (flag)
    {
        flag = false;
        for (int i=cnt-1;i>=1;i--)
        {
            if (values[i] < values[i - 1])
            {
                sum++;
                tmp = values[i];
                values[i] = values[i - 1];
                values[i - 1] = tmp;
                flag = true;
            }
        }
    }
    
    for (int i = 0; i < cnt; i++)
    {
        if (i!=0)
            std::cout << " ";
        
        std::cout << values[i] ;
    }
    std::cout  << std::endl;
    std::cout << sum << std::endl;
}
