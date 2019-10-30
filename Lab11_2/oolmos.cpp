#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Global variable, stated from book.
int timestamp;

/*
Followed the Books pseudocode for Strongly Connected Components and Depth-First Search. As represented with the specific
colors:WHITE,GREY,WHITE. Also the book stated the parent of a vertex on which i included.
Class was made with the knowledge from CSE 165.
The Vertex Struct was suggested in Page 592 from the book.
/*
Refrences:
Used this as a guide: https://www.programiz.com/dsa/graph-dfs
- On how to create edges: https://www.geeksforgeeks.org/graph-and-its-representations/
- On resizing a vector, had most trouble with this: https://www.geeksforgeeks.org/vector-resize-c-stl/
*/

class Graph
{
  //This struct includes the variables needed for depthfirst search.
  struct Vertex
  {
    int parent, discoveryTime, finishTime;
    string color;
    //Determine if it is connected to any other vertex.
    vector<int> connected;

    Vertex()
    {
      //No parent, base case color is WHITE
      parent = 0;
      color = " ";
    }

    Vertex(int p, string c) : parent(p), color(c) 
    {
    }
    ~Vertex()
    {
    }
  };

public:
  //How many vertices and edges. Vert is size of each vector below.
  int vert, edges;
  //Both the original and transposed graph, as stated from the book.
  vector<Vertex *> G;
  vector<Vertex *> Gt;
  //To determine whether to use either graph
  bool transpose;
  //for the print outs.
  vector<int> vertices;
  //Original graphs finish times and the transposed aswell.
  vector<int> orignalFinishTimes;
  vector<int> transposedFinishedTimes;

  //Default Constructor for Graph
  Graph() : vert(0), edges(0), transpose(false) {}

  //Parametrized Constructor
  Graph(int v, int e) : vert(v), edges(e), transpose(false)
  {
    vertices.resize(v);
    G.resize(v);
    Gt.resize(v);
    for (int i = 0; i < v; i++)
    {
      G[i] = new Vertex(-1, "WHITE");
      Gt[i] = new Vertex(-1, "WHITE");
    }
  }
  void setTranspose(bool t)
  {
    transpose = t;
  }
  void addEdge(int u, int v)
  {
    G[u]->connected.push_back(v);
    Gt[v]->connected.push_back(u);
  }
  //pseudocode
  void dfsVist(int index)
  {
    timestamp++;

    if (!transpose)
    {
      G[index]->discoveryTime = timestamp;
      G[index]->color = "GREY";

      for (unsigned int i = 0; i < G[index]->connected.size(); i++)
      {
        int adjacent = G[index]->connected[i];

        if (G[adjacent]->color == "WHITE")
        {
          G[adjacent]->parent = index;
          dfsVist(adjacent);
        }

        timestamp++;
        G[index]->color = "BLACK";
        G[index]->finishTime = timestamp;
      }
    }
    else
    {
      Gt[index]->discoveryTime = timestamp;
      Gt[index]->color = "GREY";

      for (unsigned int i = 0; i < Gt[index]->connected.size(); i++)
      {
        int adjacent = Gt[index]->connected[i];

        if (Gt[adjacent]->color == "WHITE")
        {
          Gt[adjacent]->parent = index;
          dfsVist(adjacent);
        }

        timestamp++;
        Gt[index]->color = "BLACK";
        Gt[index]->finishTime = timestamp;
      }
    }
    if (!transpose)
    {
      orignalFinishTimes.push_back(index);
    }
    else
    {
      transposedFinishedTimes.push_back(index);
    }
  }

  void DFS()
  {
    //Whether to use original or trasnposed.
    if (transpose)
    {
      for (int i = 0; i < vert; i++)
      {
        int j = orignalFinishTimes[vert - i - 1];

        if (Gt[j]->color == "WHITE")
        {
          dfsVist(j);
        }
      }
    }
    else
    {
      for (int i = 0; i < vert; i++)
      {
        if (G[i]->color == "WHITE")
        {
          dfsVist(i);
        }
      }
    }
  }
  void SCC()
  {
    //1st Part
    DFS();
    //2nd Part.
    setTranspose(true);
    DFS();
    
    int index = 0;

    for (int i = 0; i < vert; i++)
    {
      if (Gt[transposedFinishedTimes[i]]->parent == -1)
      {
        int currentTime = transposedFinishedTimes[index];

        for (int j = index; j <= i; j++)
        {
          int prevTime = transposedFinishedTimes[j];
          if (currentTime > prevTime)
          {
            currentTime = transposedFinishedTimes[j];
          }
        }
        for (int k = index; k <= i; k++)
        {
          vertices[transposedFinishedTimes[k]] = currentTime;
        }
        index = i + 1;
      }
    }
    //The print out
    for (int j = 0; j < vert; j++)
    {
      cout << vertices[j] << endl;
    }
  }
  ~Graph ()
  {
  }
};

int main(int argc, char const *argv[])
{
  int ver, edge;

  cin >> ver >> edge;
  Graph G(ver, edge);

  int v1, v2;

  for (int i = 0; i < edge; i++)
  {
    cin >> v1 >> v2;
    G.addEdge(v1, v2);
  }
  
  G.SCC();

  //cout << "before " << timestamp << endl;

  //cout << "after " << timestamp << endl;
  return 0;
}