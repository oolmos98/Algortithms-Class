//whehdwns

//Huffman Code        pg 431

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <math.h>
#include <queue>
#include <functional>

using namespace std;

struct Node {
    int freq;
    char character;
    Node * left;
    Node * right;
    string code;
};

string arr[100];
vector<Node> huff;


Node MinHeap(vector<Node>& huff) {
    
    int num = INT_MAX;
    int number = 0;
    for (int i = 0; i < huff.size(); i++) {
        if (num > huff[i].freq) {
            number = i;
            num = huff[i].freq;
        }
    }
    Node tempNode = huff[number];
    huff.erase(huff.begin() + number);
    
    return tempNode;
}


void print(Node * Root, string s, string arr[]) {
    Node * roots = Root;
    roots->code = s;
    
    if (Root == NULL) {
        return;
    }
    else if (roots->left == NULL && roots->right == NULL) {
        arr[roots->character] = roots->code;
    }
    else {
        if (roots->left) {
            print(roots->left, s + "0", arr);
        }
        if (roots->right) {
            print(roots->right, s + "1", arr);
        }
    }
}


Node huffman( vector<Node> &huff) {
    
    while (huff.size() != 1) {
        for (int i = 0; i < huff.size() - 1; i++) {
            
            Node * topNode = new Node;
            Node * leftNode = new Node;
            Node * rightNode = new Node;
            
            *leftNode = MinHeap(huff);
            *rightNode = MinHeap(huff);
            topNode->left = leftNode;
            topNode->right = rightNode;
            topNode->freq = leftNode->freq + rightNode->freq;
            
            huff.push_back(*topNode);
        }
    }
    return huff[0];
}



int main() {
    char charactervalue;
    int charFrequency;
    int size;
    cin >> size;
    Node node;
    node.left = node.right = NULL;
    for (int i = 0; i < size; i++)
    {
        cin >> charFrequency;
        charactervalue = i+1;
        node.freq = charFrequency;
        node.character = charactervalue;
        huff.push_back(node);
    }
    
    Node root = huffman(huff);
    
    print(&root, "", arr);
    
    for (int i = 1; i<=size; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
