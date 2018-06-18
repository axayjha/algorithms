#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <exception>
#include <string.h>

using namespace std;

#define N 9999


// -------------------IGNORE THIS GARBAGE-------------

struct InvalidBooleanException : public exception {
   const char * what () const throw () {
      return "Invalid Boolean Exception";
   }
};

istream &boolyn(istream &stream)
{
	char buf[10];
	stream >> buf;
	if (!(strcmp(buf, "yes") && strcmp(buf, "Yes") && \
		strcmp(buf, "True") && strcmp(buf, "true") && \
		strcmp(buf, "y")  && strcmp(buf, "Y")))
		stream.putback('1');
	else if (!(strcmp(buf, "no") && strcmp(buf, "No") && \
		strcmp(buf, "n") && strcmp(buf, "N") && \
		strcmp(buf, "False") && strcmp(buf, "false")))
		stream.putback('0');
	else{		
		throw InvalidBooleanException();
	}

	return stream;
}

//----------------------------------------------------


bool BellmanFord(vector<vector<int>> &adjMat, int v, int s)
{
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			for (int k = 0; k < v; k++)
				if (adjMat[s][j] > adjMat[s][k] + adjMat[k][j])
					adjMat[s][j] = adjMat[s][k] + adjMat[k][j];
	for (int j = 0; j < v; j++)
		for (int k = 0; k < v; k++)
			if (adjMat[s][j] > adjMat[s][k] + adjMat[k][j]) {
				cout << "\n\n!! Negative weight cycle exits !!\n";
				return false;
			}
	return true;			
}

int main(int argc, char const *argv[])
{
	int v, e, s; bool isDirected;
	cout << "Enter the number of vertices: ";
	cin >> v;

	std::map<char, int> vert_map;
	std::map<int, char> vert;

	cout << "Is the graph directed? (y/n): ";
	cin >> boolyn >> isDirected;

	cout << "Enter the name of the vertices: ";
	for (int i = 0; i < v; i++)
	{
		char buf;
		cin >> buf;
		vert_map[buf] = i;
		vert[i] = buf;
	}

	vector<vector<int> > adjMat(v, vector<int>(v, 0));
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			if (i!=j) adjMat[i][j] = N;

	
	cout << "Enter the number of edges: ";
	cin >> e;

	for (int _ = 0; _ < e; _++)
	{
		int u, v, weight;
		char buf1, buf2;
		cout << "Enter first vertex for edge #" << _+1 << ": ";
		cin >> buf1;
		u = vert_map[buf1];
		cout << "Enter second vertex for edge #"<< _+1 << ": ";
		cin >> buf2;
		v = vert_map[buf2];

		
		cout << "Enter weight for the edge " << buf1 << "->" << buf2 << " :";
		cin >> weight;
		adjMat[u][v] = weight;
		if (not(isDirected))
			adjMat[v][u] = weight;
		
	}

	char src;
	cout << "Enter the source vertex: ";
	cin >> src;
	s = vert_map[src];
	
	if (BellmanFord(adjMat, v, s))
	{
		cout << "\n\nSource -> vertex: weight\n";
	    for(int i=0; i<v; i++) 
	    	if (i != s) {
	    		if( adjMat[s][i] == N )
	    			cout << vert[s] << "-->" << vert[i] << ": INF" << endl;
	    		else
	    			cout << vert[s] << "-->" << vert[i] << ": " << adjMat[s][i] << endl;
	    	}
	}   
    
	return 0;
}