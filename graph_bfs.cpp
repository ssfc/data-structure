#include<iostream>
#include<vector>
using namespace std;

struct Edge
{
	int start;
	int end;
};

struct Node
{
	int key;
	int level;
};


int N; // number of vertices
int M; //  number of edges
vector<Edge> store_edge;
vector<bool> adjacency_matrix;
vector<bool> visited;


bool test_edge(int start, int end)
{
	bool flag = false;

	if(adjacency_matrix[(start-1)*N+(end-1)]==true)    flag = true;
	if(adjacency_matrix[(start-1)+(end-1)*N]==true)    flag = true;

	return flag;
}


// BFS one range;
void BFS(int i)
{
	visited[i-1] = true;
	cout<<i<<" ";

	vector<int> q;
	q.push_back(i);

	while(q.size()!=0)
	{
		int first = q.front();
		q.erase(q.begin());

		for(int j=0;j<N;j++)
		{
			if((test_edge(first, j+1) == true)&&(visited[j]==false))
			{
				visited[j] = true;
				cout<<j+1<<" ";
				q.push_back(j+1);
			}
		}


	}

}


/*
// DFS all map;
void DFSTraverse()
{
	// initialize visited matrix;
	for(int i=1;i<=N;i++)
	{
		visited[i-1] = false;
	}


	for(int i=1;i<=N;i++)
	{
		if(visited[i-1]==false)
		{
			DFS(i);
		}
	}
}
*/




int main()
{
// store edge and vertices ////////////////////////////////
	
	cin>>N;	
	cin>>M;

	store_edge.resize(M);
	for(int i=0;i<M;i++)
	{
		cin>>store_edge[i].start;
		cin>>store_edge[i].end;
	}


	// create adjacency matrix;
	for(int i=0;i<N*N;i++)
	{
		adjacency_matrix.push_back(false);
	}

	// save current amp in adjacency matrix;
	for(int i=0;i<M;i++)
	{
		int start = store_edge[i].start - 1;
		int end = store_edge[i].end - 1;

		adjacency_matrix[start*N + end] = true;
		adjacency_matrix[start + end*N] = true;
	}

//	cout<<test_edge(2, 1)<<endl;
//	cout<<test_edge(2, 4)<<endl;

	// generate visited point;
	visited.resize(N);
	for(int i=0;i<N;i++)
	{
		visited[i] = false;
	}



	BFS(1); // test BFS one range;





//	DFSTraverse();

//	bool result = test_connect();
//	cout<<result<<endl;



	return 0;
}

/*
5 3
1 2
3 4
2 5
*/