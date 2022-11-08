#include <iostream>
#include <locale>
#include <Windows.h>
#include <cmath>
#include <limits>

using namespace std;

int main()

{
    cout << INT_MAX << endl;

    setlocale(LC_ALL, "rus");

    const int N = 100;
    int a[N];
    int b[N];
    cout <<"Введите длину массива ( <= " << N << "):";
    int n;
    cin >> n;

    if ((n <= 0) || (n > N))
        cout << "Неправильный размер" << endl;


    else
    {
        int counter = 0;
        int count_int_max = 0;

        cout << "Введите элементы массива:";

        for (int i = 0; i < n; i++)
            cin >> a[i];

        int prev = INT_MIN;

        for (int k = 0; k < n; k++)
        {
            int min = INT_MAX;

            for (int i = 0; i < n; i++)
            {
                if (a[i] < min && a[i] > prev)
                {
                    min = a[i];
                }
            }

            if (min == INT_MAX) count_int_max++;

            b[k] = min;
            prev = min;

        }

        int c[n - count_int_max];

        for (int i = 0; i < n - count_int_max; i++)
        {
            c[i] = b[i];
        }

        for (int i = 0; i < n - count_int_max; i++)
        {
            cout << c[i] << " ";
        }

        cout << endl;
    }

    system("pause");
    return 0;

    //сортировать нельзя. нужно сразу записывть в нужном порядке.
}
