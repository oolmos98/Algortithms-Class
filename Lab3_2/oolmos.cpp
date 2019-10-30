#include <iostream>
#include <limits.h>
using namespace std;

//Reused Fall 2018 CSE 100 Lab, also with the help from the textbook.

int findMaxCrossingSum(int A[], int low, int mid, int high)
{
  int leftsum = INT_MIN, rightsum = INT_MIN;
  int sum = 0;

  for (int i = mid; i >= low; i--)
  {
    sum += A[i];
    if (sum > leftsum)
    {
      leftsum = sum;
    }
  }
  sum = 0;
  for (int i = mid + 1; i <= high; i++)
  {
    sum += A[i];
    if (sum > rightsum)
    {
      rightsum = sum;
    }
  }
  return (leftsum + rightsum);
}

int findMaxSubArray(int A[], int low, int high)
{
  if (high == low)
  {
    return A[low];
  }
  int mid = (low + high) / 2;

  int left = findMaxSubArray(A, low, mid);
  int right = findMaxSubArray(A, mid + 1, high);
  int crosssum = findMaxCrossingSum(A, low, mid, high);

  if (left >= right && left >= crosssum)
    return left;
  else if (right >= left && right >= crosssum)
    return right;
  else
    return crosssum;
}

int main(int argc, char **argv)
{

  int size = 0;

  cin >> size;

  int A[size];

  for (int i = 0; i < size; i++)
  {
    cin >> A[i];
  }

  int value = findMaxSubArray(A, 0, size - 1);

  cout << value;

  return 0;
}
