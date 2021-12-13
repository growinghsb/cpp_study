#include<cassert>
#include<iostream>

using std::cout;
using std::endl;

class Graph {
public:
	Graph(int nodeCount)
		:mNodeCount(nodeCount)
	{
		for (int i = 0; i < MAX_VERTICES; ++i)
		{
			for (int j = 0; j < MAX_VERTICES; ++j)
			{
				mAdjMat[i][j] = 0;
			}
		}
	}

	void setNodeCount(int nodeCount) 
	{
		assert(0 < nodeCount && MAX_VERTICES > nodeCount);
		
		mNodeCount = nodeCount;
	}

	void setEdge(int start, int end) 
	{
		assert(0 <= start && 0 <= end && MAX_VERTICES > start && MAX_VERTICES > end);

		/*
			무방향 그래프이기 때문에 
			양쪽으로 모두 왔다 갔다 할 수 있다. 
			해서 양쪽에서 모두 표시를 해준다.
			ex) 1 <---> 3
		*/
		mAdjMat[start][end] = 1;
		mAdjMat[end][start] = 1;
	}

	void printAdj()
	{
		for (int i = 0; i < mNodeCount; ++i) 
		{
			for (int j = 0; j < mNodeCount; ++j) 
			{
				cout << mAdjMat[i][j];
			}
			cout << endl;
		}
	}

	enum { MAX_VERTICES = 50 };
	int mAdjMat[MAX_VERTICES][MAX_VERTICES];
	int mNodeCount;
};

int main()
{
	Graph graph(4);

	graph.setNodeCount(4);
	
	graph.setEdge(0, 1);
	graph.setEdge(0, 2);
	graph.setEdge(0, 3);
	graph.setEdge(1, 2);
	graph.setEdge(2, 3);

	graph.printAdj();

	return 0;
}