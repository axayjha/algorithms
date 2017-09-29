#include <iostream>
#include <queue>
#include <string>
#include <bits/stdc++.h>
#include <list>
#include <vector>
using namespace std;


class vertex{
	string name;
	string colour;
public:
	vertex(){};
	vertex(string s){name=s; colour="white";}	
	string getName(){return name;}
	string getColour(){return colour;}
	void setColour(string c){colour = c;}
};

 
int main()
{
	int n;
	cout << "Enter the number of vertices: ";
	cin >> n;
    vector <vertex> vertices;
    cout << "Enter the name of vertices" << endl;
    for(int i=0; i<n; i++)
    {
    	string name;
    	cin >> name;
    	vertices.push_back(vertex(name));
    }
    

    list <vertex *> adjlist[n];
    unordered_map<string, list<vertex*>> Adj;

    for(int i=0; i<n; i++)
    {
    	cout << "Enter the number of vertices adjacent to " << vertices[i].getName() << ": " << endl;
    	int numOfAdjV;
    	cin >> numOfAdjV;
    	for(int j=0; j<numOfAdjV; j++)
    	{
    		cout << "Enter the name of adjacent vertex "<< j+1 << "/" << numOfAdjV << " : ";
    		string nameOfAdjV;
    		cin >> nameOfAdjV;

    		for(int k=0; k<n; k++)
    			if(nameOfAdjV == vertices[k].getName())
    				adjlist[i].push_back(&vertices[k]);
    	}

    	Adj[vertices[i].getName()] = adjlist[i];
    }


    queue<vertex *> Q;
    vertices[0].setColour("black");
    Q.push(&vertices[0]);


    while(!Q.empty())
    {
    	vertex *v = Q.front();
    	Q.pop();

    	for(list <vertex *> :: iterator i=Adj[v->getName()].begin(); i!=Adj[v->getName()].end(); i++)
    	{
    		if((*i)->getColour() == "white")
    		{
    			(*i)->setColour("gray");
    			Q.push(*i);    
    			cout << (*i)->getName() << endl;			
    		}
    	}
    	
    	v->setColour("black");    	

    }
}