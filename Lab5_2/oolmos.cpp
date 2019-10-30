#include <iostream>
#include <vector>
//Used my Fall2018 Lab and referenced it from the book.

using namespace std;
//pseudocode with vector of arrays
void countingSort(vector<int> A[], vector<int> B[], int n, int k)
{
        int C[10];
        for (int j = 0; j < 10; j++)
        { //without this, segmentation fault
                C[j] = 0;
        }
        for (int j = 0; j < n; j++)
        {
                C[A[j][k]]++;
        }
        for (int i = 1; i < 10; i++)
        {
                C[i] = C[i] + C[i - 1];
        }

        for (int j = n - 1; j >= 0; j--)
        {
                B[C[A[j][k]] - 1] = A[j];
                C[A[j][k]]--;
        }
        for (int i = 0; i < n; i++)
        {
                A[i] = B[i];
        }
}

void radixSort(vector<int> A[], int d)
{
        vector<int> *B = new vector<int>[d];
        for (int i = 10; i > 0; i--)
        {
                countingSort(A, B, d, i - 1);
        }
        delete[] B;
}

int main(int argc, char const *argv[])
{

        int x = 0;
        cin >> x;

        vector<int> *A = new vector<int>[x];

        for (int i = 0; i < x; i++)
        {
                for (int j = 0; j < 10; j++)
                {
                        int y;
                        cin >> y;
                        A[i].push_back(y);
                }
        }
        radixSort(A, x);

        vector<int>::iterator j;

        for (int i = 0; i < x; i++)
        {
                for (j = A[i].begin(); j != A[i].end(); j++)
                {
                        cout << *j << ";";
                }
                cout << endl;
        }
        delete[] A;

        return 0;
}
