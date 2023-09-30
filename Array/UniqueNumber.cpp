#include <iostream>
using namespace std;

void uniqueNumber(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                arr[i] = arr[j] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            cout << arr[i] << endl;
        }
    }
}

int main()
{

    int n;
    cout << "enter the length of the element:";
    cin >> n;

   int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "the unique number are" << endl;
    uniqueNumber(arr, n);
    return 0;
}