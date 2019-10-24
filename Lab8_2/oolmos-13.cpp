#include <iostream>
#include <limits.h>
using namespace std;

//Used the books pseudocode for this assignment.

void printOptimalParenthis(int **s, int i, int j)
{
        if (i == j)
        {
                cout << "A" << i - 1;
                return;
        }
        else
        {
                cout << "(";
                printOptimalParenthis(s, i, s[i][j]);
                printOptimalParenthis(s, s[i][j] + 1, j);
                cout << ")";
        }
}

void matrixChainOrder(int *p, int size)
{
        int n = size;
        int** m = new int*[n];
        int **s = new int *[n];
        for (int i = 0; i < n; i++)
        {
                s[i] = new int[n];
                m[i] = new int[n];
        }
        for (int i = 0; i < n; i++)
        {
                m[i][i] = 0;
        }
        for (int l = 2; l < n; l++)
        {
                for (int i = 1; i < n - l + 1; i++)
                {
                        int j = i + l - 1;
                        m[i][j] = INT_MAX;
                        for (int k = i; k <= j - 1; k++)
                        {
                                int q = (m[i][k] + m[k + 1][j]) + (p[i - 1] * p[k] * p[j]);
                                if (q < m[i][j])
                                {
                                        m[i][j] = q;
                                        s[i][j] = k;
                                }
                        }
                }
        }
        cout << m[1][n - 1] << endl;
        printOptimalParenthis(s, 1, n - 1);
        cout << endl;
}

int main(int argc, char const *argv[])
{

        int x = 0;
        cin >> x;

        int *A = new int[x+1];

        for (int i = 0; i <= x; i++)
        {
                cin >> A[i];
        }

        matrixChainOrder(A, x + 1);

        delete[] A;

        return 0;
}
