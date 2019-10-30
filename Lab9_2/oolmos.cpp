#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//Used the pseudo code and help with some online resources on minHeap
//and how to use priority_queue from STL.
//Node struct was learned from CSE30 in which i reused.
//Class format learned in CSE 165.
//Resources:
//-> https://en.cppreference.com/w/cpp/container/priority_queue

// I used this one to figure out the compare function in the Queue structure
//-> https://stackoverflow.com/questions/15646780/priority-queue-of-nodes

//For the print out, used these variables to print the frequency in the correct order.
char c[6];
string f[6];

class minHeap
{
private:
  struct node
  {
    char characters;
    int freq;
    node *left;
    node *right;

    node()
    {
      characters = ' ';
      freq = 0;
      left = NULL;
      right = NULL;
    }
    node(char character, int freq_)
    {
      characters = character;
      freq = freq_;
      left = NULL;
      right = NULL;
    }
    node(char character, int freq_, node *l, node *r)
    {
      characters = character;
      freq = freq_;
      left = l;
      right = r;
    }
  };

public:
  //Helped with this struct online, resources on the top of this file.
  struct compare
  {
    bool operator()(node *left, node *right) const
    {
      return (left->freq > right->freq);
    }
  };

  void printCode()
  {
    int i = 0;
    while (i != 6)
    {
      //cout << c[i] << ":" << f[i] << endl;

      for (int j = 0; j < 6; j++)
      {
        //cout<< c[j]<<endl;
        if (c[j] == char(65 + i))
        {
          cout << c[j] << ":" << f[j] << endl;
        }
      }
      i++;
    }
  }
  void buildCode(node *root, string code)
  {
    if (root == NULL)
      return;

    if (root->characters != 'z')
    {
      int index = root->characters - 65;
      //cout << code << endl;

      c[index] = root->characters;
      f[index] = code;
    }

    buildCode(root->left, code + "0");
    buildCode(root->right, code + "1");
  }

  void huffmanCode(char *characters, int *freq)
  {
    //Help with priority_queue from resource.
    priority_queue<node *, vector<node *>, compare> minHeap;

    for (int i = 0; i < 6; i++)
    {
      minHeap.push(new node(characters[i], freq[i]));
    }
    node *left;
    node *right;
    node *temp;

    //From pseudocode
    while (minHeap.size() > 1)
    {
      left = minHeap.top();
      minHeap.pop();
      right = minHeap.top();
      minHeap.pop();

      //'z' means from pseudocode in book to show that this node is the combined.
      temp = new node('z', left->freq + right->freq, left, right);
      minHeap.push(temp);
    }
    buildCode(minHeap.top(), "");
    printCode();
  }
};
int main(int argc, char const *argv[])
{
  const int size = 6;

  minHeap A;
  char characters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
  int freq[size];
  for (int i = 0; i < size; i++)
  {
    cin >> freq[i];
  }

  A.huffmanCode(characters, freq);

  return 0;
}