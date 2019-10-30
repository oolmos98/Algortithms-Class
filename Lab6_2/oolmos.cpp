#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//Used my Fall2018 Lab and referenced it from the book.

int hashFunction(int key, int size)
{
  return (key % size);
}

void hashTableSearch(list<int> *B, int index, int key, int size)
{
  int k = 0;

  for (list<int>::iterator i = B[index].begin(); i != B[index].end(); ++i)
  {

    if (*i == key)
    {
      cout << key << ":FOUND_AT" << index << "," << k << ";" << endl;
      //cout << "++++++++++++++++++++" << endl;
      return;
    }
    k++;
  }
  cout << key << ":NOT_FOUND;" << endl;
  //cout << "++++++++++++++++++++" << endl;
}

void hashTableDelete(list<int> *B, int index, int key, int size)
{

  for (list<int>::iterator i = B[index].begin(); i != B[index].end(); ++i)
  {
    if (*i == key)
    {
      B[index].erase(i);
      cout << key << ":DELETED;" << endl;
      //cout << "++++++++++++++++++++" << endl;
      return;
    }
  }

  cout << key << ":DELETE_FAILED;" << endl;
  //cout << "++++++++++++++++++++" << endl;
}
void hashTableInsert(list<int> *B, int index, int key)
{
  B[index].push_front(key);
}
void hashTablePrint(list<int> *B, int size)
{
  for (int j = 0; j < size; j++)
  {
    cout << j << ":";
    for (list<int>::iterator i = B[j].begin(); i != B[j].end(); ++i)
    {
      cout << *i;
      list<int>::iterator k = i;
      if ((++k) != B[j].end())
      {
        if (B[j].size() != 0)
        {
          cout << "->";
        }
      }
    }
    if (B[j].size() != 0)
    {
      cout << "->";
    }
    cout << ";";

    cout << endl;
  }

  //cout << ";";

  //cout << "++++++++++++++++++++" << endl;
}

int main(int argc, char const *argv[])
{
  int x;
  cin >> x;
  list<int> *A = new list<int>[x];
  char toDo;
  int key;
  int index = 0;
  cin >> toDo;
  while (toDo != 'e')
  {
    if (toDo != 'o')
    {
      cin >> key;
    }
    if (toDo == 'o')
    {
      hashTablePrint(A, x);
    }
    if (toDo == 'i')
    {
      index = hashFunction(key, x);
      hashTableInsert(A, index, key);
    }
    if (toDo == 'd')
    {
      index = hashFunction(key, x);
      hashTableDelete(A, index, key, x);
    }
    if (toDo == 's')
    {
      index = hashFunction(key, x);
      hashTableSearch(A, index, key, x);
    }
    cin >> toDo;
  }
  delete[] A;
  return 0;
}
