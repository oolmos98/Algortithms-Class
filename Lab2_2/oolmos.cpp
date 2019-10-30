#include <iostream>
#include <limits.h>
using namespace std;
//Referenced from the textbook and reused my lab from Fall 2018.
void Merge(int B[], int beg, int mid, int end)
{
        int n = mid - beg + 1,
            m = end - mid;
        int L[n + 1], R[m + 1];

        for (int i = 0; i < n; i++)
        {
                L[i] = B[beg + i];
        }

        for (int j = 0; j < m; j++)
        {
                R[j] = B[mid + j + 1];
        }

        L[n] = INT_MAX;
        R[m] = INT_MAX;
        int j = 0, k = 0;
        for (int i = beg; i <= end; i++)
        {
                if (L[j] <= R[k])
                {
                        B[i] = L[j];
                        j++;
                }
                else
                {
                        B[i] = R[k];
                        k++;
                }
        }
}

void MergeSort(int A[], int b, int e)
{
        if (b < e)
        {
                int mid = (b + e) / 2;

                MergeSort(A, b, mid);
                MergeSort(A, mid + 1, e);
                Merge(A, b, mid, e);
        }
}

int main(int argc, char const *argv[])
{
        int i = 0, x = 0;
        cin >> x;
        int A[x];
        while (i < x)
        {
                cin >> A[i];
                i++;
        }

        MergeSort(A, 0, x - 1);

        i = 0;
        while (i < x)
        {
                cout << A[i] << ";";
                i++;
        }
        //cout << endl;

        return 0;
}
