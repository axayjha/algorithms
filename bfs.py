class vertex(object):
    def __init__(self, name):
        self.name=name
        self.colour=None
        self.d=None
        self.p=None

s=vertex('s')
b=vertex('b')
c=vertex('c')
d=vertex('d')
e=vertex('e')
f=vertex('f')
g=vertex('g')

V=[s,b,c,d,e,f,g]

for i in V:
    i.colour="white"
    i.d = None
    i.p=None

V[0].colour = "gray"
V[0].d=0
V[0].p=None

G={s:[b,c], b:[s,d,g], c:[s,f], d:[b,e], e:[d], f:[c], g:[b]}

Q=[]
Q.append(V[0])
while(len(Q)!=0):
    u=Q.pop(0)
    for v in G[u]:
        if v.colour=="white":
            v.colour="gray"
            v.d=u.d+1
            v.p=u
            Q.append(v)
            print(v.name)        
    u.colour="black"    
