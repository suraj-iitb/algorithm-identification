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

int binary_search(int x, int n, int arr[])
{
    int left = 0;
    int right = n;

    while (left < right)
    {
        int mid = (left + right) / 2;

        if (x == arr[mid])
        {
            return mid;
        }

        else if (x < arr[mid])
        {
            right = mid;
        }

        else if (x > arr[mid])
        {
            left = mid + 1;
        }

    }

    return -1;

}

int main (void)
{
    int n, p;
    scanf("%i", &n);

    int elements[n], copy_elements[n];
    int counter = 1;

    for (int i = 0; i < n; i++)
    {
        scanf("%i", &elements[i]);
    }

    scanf("%i", &p);

    int match[p], copy_match[p];

    for (int i = 0; i < p; i++)
    {
        scanf("%i", &match[i]);

        if (i == 0)
        {
            copy_match[0] = match[0];
        }

        int condition_counter = 0;

        for (int j = 0; j < counter; j++)
        {
            if (match[i] == copy_match[j])
            {
                condition_counter++;
                break;
            }

        }

        if (condition_counter == 0)
        {
            copy_match[counter] = match[i];
            counter++;
        }
    }

    int words = 0;

    for (int i = 0; i < counter; i++)
    {
        int searching = match[i];
        int binary_return = binary_search(searching, n, elements);


        if (binary_return != -1)
        {
            words++;
        }

    }

    printf("%i\n", words);

}
