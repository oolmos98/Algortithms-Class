#include <iostream>
#include <string>
#include <sstream>

using namespace std;
//Used my CSE100 Fall2018 lab!
//Pseudo from textbook
//Reading the strings and integers was tricky, found a source that deals with sstream.

//Node struct built from CSE30 old lab
class Node
{
public:
  int key;
  Node *parent;
  Node *left;
  Node *right;
  static Node *r;

  Node()
  {
    //key = 0;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
  }
  Node(int data)
  {
    key = data;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
  }

  ~Node()
  {
  }
};
Node *Node::r;
///////////////////////////////////Pseudo from textbook
Node *BST_Minimum(Node *root)
{
  Node *temp = root;
  while (temp->left != nullptr)
  {
    temp = temp->left;
  }
  return temp;
}
Node *BST_Successor(Node *root)
{
  if (root->right != nullptr)
    return BST_Minimum(root->right);

  Node *y = root->parent;
  while (y != nullptr && root == y->right)
  {
    root = y;
    y = y->parent;
  }
  return y;
}

Node *BST_Search(Node *root, int key)
{
  Node *temp = root;
  while (temp != nullptr && key != temp->key)
  {
    if (key < temp->key)
      temp = temp->left;
    else
      temp = temp->right;
  }
  return temp;
}

void BST_Insert(Node *root, Node *child)
{
  Node *y = nullptr;
  Node *x = Node::r;
  while (x != nullptr)
  {
    y = x;
    if (child->key < x->key)
    {
      x = x->left;
    }
    else
    {
      x = x->right;
    }
  }
  child->parent = y;
  if (y == nullptr)
  {
    Node::r = child;
  }
  else if (child->key < y->key)
  {
    y->left = child;
  }
  else
  {
    y->right = child;
  }
}

void transplant(Node *root, Node *u, Node *v)
{
  if (u->parent == nullptr)
  {
    Node::r = v;
  }
  else if (u == u->parent->left)
  {
    u->parent->left = v;
  }
  else
  {
    u->parent->right = v;
  }
  if (v != nullptr)
  {
    v->parent = u->parent;
  }
}

void BST_Delete(Node *root, Node *z)
{
  if (!root || !z)
    return;

  if (z->left == nullptr)
  {
    transplant(root, z, z->right);
  }
  else if (z->right == nullptr)
  {
    transplant(root, z, z->left);
  }
  else
  {
    Node *y = BST_Minimum(z->right);
    if (y->parent != z)
    {
      transplant(root, y, y->right);
      y->right = z->right;
      y->right->parent = y;
    }
    transplant(root, z, y);
    y->left = z->left;
    y->left->parent = y;
  }
}

void BST_inOrder(Node *root)
{
  if (root != nullptr)
  {
    BST_inOrder(root->left);
    cout << root->key << endl;
    BST_inOrder(root->right);
  }
}
//Pre and Post figured out with reference below
void BST_Pre(Node *root)
{
  if (root != nullptr)
  {
    cout << root->key << endl;
    BST_Pre(root->left);
    BST_Pre(root->right);
  }
}

void BST_Post(Node *root)
{
  if (root != nullptr)
  {
    BST_Post(root->left);
    BST_Post(root->right);
    cout << root->key << endl;
  }
}
void deleteTree(Node *root)
{
  if (root != nullptr)
  {
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
  }
}
int main(int argc, char const *argv[])
{

  Node::r = nullptr;

  int count = 0;
  //With help of references included below
  char input[100];

  while (cin.getline(input, 100))
  {
    string toDo(input);
    if (toDo.size() == 0)
      continue;
    if (toDo[0] == 'e')
      break;

    //Printing checks
    if (toDo.substr(0, 3) == "oin")
    {
      BST_inOrder(Node::r);
      //cout << "++++++++++++++++++++" << endl;
      continue;
    }
    if (toDo.substr(0, 4) == "opre")
    {
      BST_Pre(Node::r);
      //cout << "++++++++++++++++++++" << endl;
      continue;
    }

    if (toDo.substr(0, 5) == "opost")
    {
      BST_Post(Node::r);
      //cout << "++++++++++++++++++++" << endl;
      continue;
    }

    int key;
    stringstream convert_stm(toDo.substr(1, toDo.size() - 1));
    convert_stm >> key;
    if (toDo.substr(0, 1) == "i")
    {
      if (count == 0)
      {
        Node::r = new Node(key);
        count++;
        continue;
      }
      BST_Insert(Node::r, new Node(key));
      count++;
      continue;
    }

    else if (toDo.substr(0, 1) == "d")
    {
      BST_Delete(Node::r, BST_Search(Node::r, key));
      if (count > 0 && BST_Search(Node::r, key) != nullptr)
        count--;
      //cout << count << endl;
      continue;
    }
  }
  deleteTree(Node::r);
  return 0;
}

/*References
http://www.cplusplus.com/reference/string/string/substr/
http://www.cplusplus.com/reference/sstream/stringstream/
https://www.programiz.com/dsa/tree-traversal

*/
