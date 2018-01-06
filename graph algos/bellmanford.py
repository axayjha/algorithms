##
##  Bellman-Ford algorithm
##
##  Akshay Anand

class Graph(object):
    """
        Defines the data structure to represent graph
        and do operations easily.
        Makes use of hashtables and list.
    """
    def __init__(self):        
        self.vertices = {}     # {vertex : [distance, parent]}
        self.adjList  = {}     # {vertex1: {vertex2 : weight}}
        
    def addVertex(self, v):
        """
            initializes all vertices with infinite distance
            and no parent
        """
        self.vertices[v] = [9999, None] 

    def addEdge(self, a, b, w):
        """
            adds all edges twice with same weight
            if they are undirected
        """
        if a in self.adjList:
            self.adjList[a][b] = w            
        else:
            self.adjList[a] = {}
            self.adjList[a][b] = w
        if not directed:    
            if b in self.adjList:
                self.adjList[b][a] = w
            else:
                self.adjList[b] = {}
                self.adjList[b][a] = w

    def show(self):
        """
            prints the solution
        """
        print("Vertex   Parent  Distance")
        for i in self.vertices:
            print("   "+str(i)+"\t "+str(self.vertices[i][1])+"  \t   "+str(self.vertices[i][0]))
            

def relax(G, a, b):
    """
        relaxes edge in favour of choosing shorter path
    """
    if G.vertices[b][0] > G.vertices[a][0] + G.adjList[a][b]:
        G.vertices[b][0] = G.vertices[a][0] + G.adjList[a][b]
        G.vertices[b][1] = a
    
            
def bellmanford(G, s):
    """ 
        solves the single-source shortest-paths problem in
        the general case in which edge weights may be negative
    """
    G.vertices[s][0] = 0
    for _ in range(len(G.vertices)-1): ## O(VE), three loops may make it look otherwise
        for i in G.adjList:
            for j in G.adjList[i]:
                relax(G, i, j)
    for i in G.adjList:       
        for j in G.adjList[i]:
            if G.vertices[i][0] > G.vertices[j][0] + G.adjList[i][j]:                
                return False    # if -ve egde cycle exits
    print("Source = "+str(s))
    G.show()
    return True    
        
# a ---4--c
# | \      \1
# |  \      \
# 4   7       e
# |    \      /
# |      \   /1
# b---2----d

G = Graph()
        
n = int(input("Enter the number of vertices: "))
for i in range(n):
    v = input("Enter the name of vertex " + str(i+1) + ": ")
    G.addVertex(v)
directed = input("Is the graph directed (y/n): ")
if directed=="y": directed = True
else: directed = False 
    
m = int(input("Enter the number of edges: "))
for i in range(m):
    print("Enter details for egde #" + str(i+1) + ": ")
    v1 = input("Enter the name of vertex 1: ")
    v2 = input("Enter the name of vertex 2: ")
    w  = float(input("Enter the weight: "))
    G.addEdge(v1, v2, w)
    
s = input("Enter source vertex: ")

negative_cycle = bellmanford(G, s)
print("Negative weight cycle: " + str(not negative_cycle))
            
