#include <iostream>
#include <utility>

using namespace std;

//Used my Fall 2018 CSE100 Lab and used the text book psuedo code.
int heapSize = 0;

void maxHeap(int *A, int i)
{

        int l = (2 * i);
        int r = (2 * i) + 1;
        int largest = 0;

        if (l <= heapSize && A[l] > A[i])
        {
                largest = l;
        }
        else
                largest = i;

        if (r <= heapSize && A[r] > A[largest])
        {
                largest = r;
        }

        if (largest != i)
        {
                swap(A[i], A[largest]);
                maxHeap(A, largest);
        }
}

void buildMaxHeap(int *A, int size)
{

        for (int i = size / 2; i >= 0; i--)
        {
                maxHeap(A, i);
        }
}

void heapSort(int *A, int size)
{
        heapSize = size - 1;
        buildMaxHeap(A, size);

        for (int i = size - 1; i >= 1; i--)
        {
                swap(A[0], A[i]);
                heapSize -= 1;
                maxHeap(A, 0);
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

        heapSort(A, x);

        i = 0;
        while (i < x)
        {
                cout << A[i] << ";";
                i++;
        }
        delete[] A;
        return 0;
}
