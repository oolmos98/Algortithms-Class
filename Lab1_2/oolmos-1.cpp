#include <iostream>

using namespace std;
//From CSE100 Fall 2018, reusing my lab.
void insertionSort(int *A, int size)
{
        for (int i = 1; i < size; i++)
        {
                int key = A[i];
                int j = i - 1;
                while (A[j] > key && j >= 0)
                {
                        A[j + 1] = A[j];
                        j = j - 1;
                }
                A[j + 1] = key;
                for (int k = 0; k <= i; k++)
                {
                        cout << A[k] << ";";
                }
                cout << endl;
        }
}
int main(int argc, char const *argv[])
{
        int x;
        cin >> x;
        int num[x];
        for (int i = 0; i < x; i++)
        {
                cin >> num[i];
        }

        insertionSort(num, x);

        return 0;
}
