class pqueue(object):
    def __init__(self, List=None):
        self.list = List

    def extract_min(self):
        a= sorted(self.list, key= lambda l: l.key)[0]
        self.list.remove(a)
        return a      
        
        

class vertex(object):
    def __init__(self, name):
        self.name=name
        self.key=99999
        self.p=None

class graph(object):
    def __init__(self):
        self.V = []
        self.Adj = {}


def w(u,v):
    W = { a: {b:1 ,c:10, d:3}, b:{a:1, e:2}, c:{a:10, d:4}, d:{c:4, e:15, a:3}, e:{b:2, d:15} }
    return W[u][v]

a=vertex('a')
b=vertex('b')
c=vertex('c')
d=vertex('d')
e=vertex('e')
a.key=0
G = graph()
G.V = [a,b,c,d,e]
G.Adj = {a:[b,c,d], b:[a,e], c:[a,d], d:[e,c], e:[b,d]}

Q=pqueue(G.V[:])
weight=0
while(Q.list!=[]):
    u=Q.extract_min()
    for v in G.Adj[u]:
        if v in Q.list and w(u,v) < v.key:
            v.p = u
            v.key = w(u,v)
            
for i in G.V[1:]:
    weight+=i.key
    print(i.name + " " + i.p.name)
print("Weight of the mst: " + str(weight)) 
