#include <stdio.h>

void remove_occurences(int x, int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            arr[i] = -1;
        }
    }
}

int main (void)
{
    int n, p;
    scanf("%i", &n);

    int list[n], match[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%i", &list[i]);
    }

    scanf("%i", &p);

    for (int i = 0; i < p; i++)
    {
        scanf("%i", &match[i]);
    }

    int counter = 0;

    for (int i = 0; i < p; i++)
    {
        int searching = match[i];
        for (int j = 0; j < n; j++)
        {
            if (searching == list[j])
            {
                remove_occurences(searching, n, list);
                counter++;
            }

        }

    }

    printf("%i\n", counter);
}
