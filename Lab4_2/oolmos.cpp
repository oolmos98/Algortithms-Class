#include <iostream>
#include <utility>
#include <ctime>
#include <cstdlib>

using namespace std;
//FAll 2018 CSE100 and used the textbooks pseudo.
int partition(int *A, int p, int r)
{
        int x = A[r];
        int i = p - 1;
        for (int j = p; j <= r - 1; j++)
        {
                if (A[j] <= x)
                {
                        i++;
                        swap(A[i], A[j]);
                }
        }
        swap(A[i + 1], A[r]);
        return i + 1;
}

int randomizedPartition(int *A, int p, int r)
{
        srand(time(0));
        int i = (rand() % (r - p)) + p;
        //cout<< p << " " << r << " " << i << " "<< endl;;
        swap(A[i], A[p]);

        return partition(A, p, r);
}

void QUICKSORT(int *A, int p, int r)
{
        if (p < r)
        {

                int q = randomizedPartition(A, p, r);
                QUICKSORT(A, p, q - 1);
                QUICKSORT(A, q + 1, r);
        }
}

int main(int argc, char const *argv[])
{
        int i = 0, x = 0;
        cin >> x;
        int *A = new int[x];
        while (i < x)
        {
                cin >> A[i];
                i++;
        }

        QUICKSORT(A, 0, x - 1);

        i = 0;
        while (i < x)
        {
                cout << A[i] << ";";
                i++;
        }
        delete[] A;
        return 0;
}
