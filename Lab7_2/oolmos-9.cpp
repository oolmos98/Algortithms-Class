#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

//Used the textbooks psuedocode and recieved help with the tuple structure from Jefferson Santiago.
//Tuple needs variables in the heap not in the stack.
tuple<int *, int *> extendedBottomUpCutRod(int *p, int n)
{
  int *r = new int[n + 1];
  int *s = new int[n + 1];
  r[0] = 0;

  for (int i = 1; i <= n; i++)
  {
    int q = INT_MIN;
    for (int j = 0; j < i; j++)
    {
      if (q < (p[j] + r[i - j - 1]))
      {
        q = p[j] + r[i - j - 1];
        s[i] = j + 1;
      }
    }
    r[i] = q;
  }
  return make_tuple(r, s);
}

void printCutRodSolution(int *p, int n)
{
  int *r = new int[n];
  int *s = new int[n];
  tie(r, s) = extendedBottomUpCutRod(p, n);

  cout << r[n] << endl;
  int size = n;
  while (size > 0)
  {
    cout << s[size] << " ";
    size -= s[size];
  }
  cout << -1 << endl;
  delete[] r;
  delete[] s;
}

int main()
{
  int size;
  cin >> size;
  int *A = new int[size];
  for (int i = 0; i < size; i++)
  {
    cin >> A[i];
  }
  printCutRodSolution(A, size);

  delete[] A;
  return 0;
}
