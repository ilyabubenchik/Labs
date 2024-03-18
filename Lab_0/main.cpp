#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;


void vivod(int n, int m, float** a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << "   ";
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    ofstream out("C:\\Users\\nothi\\OneDrive\\Desktop\\out.txt");

    if (!out.is_open())
    {
        cerr << "File open error!";
        return -1;
    }

    int K;
    cout << "Введите K: ";
    cin >> K;

    int min, max;
    cout << "Введите минимальное число: ";
    cin >> min;
    cout << "Введите максимальное число: ";
    cin >> max;

    if (min > max)
    {
        cerr << "Минимальное число не может быть больше максимального!";
        return -2;
    }

    // random
    int n = (rand() % ((max + 1) - min) + min);
    int m = (rand() % ((max + 1) - min) + min);
    cout << n << endl;
    cout << m << endl;
    cout << endl;

    // array
    float** a = new float* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new float[m];
    }

    // flags
    int pn, pm;
    if (n > 2 && m > 2)
    {
        if (n % 2 != 0)
        {
            pn = (float)n / 2 - 0.5;
        }
        else
        {
            pn = (float)n / 2 - 1;
        }

        if (m % 2 != 0)
        {
            pm = (float)m / 2 - 0.5;
        }
        else
        {
            pm = (float)m / 2 - 1;
        }
        cout << pn << " " << pm << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                do
                {
                    a[i][j] = float(rand() % ((99 - (-99) + 1) + (-99))) / 1000;
                }
                while (a[i][j] == 0);
                if (n % 2 == 0)
                {
                    if (i == pn || i == (pn + 1))
                    {
                        a[i][j] = K;
                    }
                }
                else
                {
                    if (i == pn)
                    {
                        a[i][j] = K;
                    }
                }
                if (m % 2 == 0)
                {
                    if (j == pm || j == (pm + 1))
                    {
                        a[i][j] = -K;
                        if (i == pn)
                        {
                            a[i][j] = 0;
                        }
                        if (n % 2 == 0 && (i == pn || i == (pn + 1)))
                        {
                            a[i][j] = 0;
                        }
                    }
                }
                else
                {
                    if (j == pm)
                    {
                        a[i][j] = -K;
                        if (i == pn)
                        {
                            a[i][j] = 0;
                        }
                        if (n % 2 == 0 && (i == pn || i == (pn + 1)))
                        {
                            a[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                do
                {
                    a[i][j] = float(rand() % ((99 - (-99) + 1) + (-99))) / 1000;
                }
                while (a[i][j] == 0);
            }
        }
    }

    // file out
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            out << a[i][j] << "   ";
        }
        out << "\n";
    }

    // string Aa
    string abc = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    string Aa = { char(abc[K + 4]) , char(tolower(abc[K + 4])) };

    // file out
    cout << Aa << endl;
    for (int i = 0; i < Aa.length(); i++)
    {
        out << Aa[i];
    }
    out.close();

    // out
    vivod(n, m, a);

    // delete
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
