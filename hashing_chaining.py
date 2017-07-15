## Hash table with chaining implementation
##
## Akshay
## 15/07/2017

class Node(object):
    """Linked list node"""
    def __init__(self, data):
        # CONSTRUCTOR
        self.data=data
        self.next=None

    def __str__(self):
        """ prints the node """
        return self.data

    def getData(self):
        """ returns the data in the node"""
        return self.data

    def getNext(self):
        """ returns the next node"""
        return self.next

    def setData(self, data):
        """ sets the data of the node"""
        self.data=data

    def setNext(self, Next):
        """ sets the next node """
        self.next = Next


class List(object):
    """Linked list class"""
    def __init__(self):
        # CONSTRUCTOR       
        # No params
        self.head = None

    def push(self, data):
        """ pushes the data to the start of the list """
        if(self.head==None):
            self.head = Node(data)
        else:
            newnode=Node(data)
            newnode.setNext(self.head)
            self.head = newnode

    def __str__(self):
        """ prints the list """
        out="[ "
        node=self.head
        while node!=None:
            out+= str(node.getData())+" "
            node = node.getNext()
        out+="]"
        return out

    def delete(self, x):
        """deletes node with value x"""
        node=self.head
        if node.getData()==x:
            self.head=self.head.getNext()
            return None
        while node.getNext()!=None:
            # O(n) worst case running time :/ 
            if node.getNext().getData() == x:
                node.setNext(node.getNext().getNext())
                return None
            node = node.getNext()
        print("Element not found")        
            
        
        

class Table(object):   
    """
        Hash table with chaining implementation        
        *Stores only ints*
    """
    def __init__(self):
        """
            //CONSTRUCTOR            
        """
        self.table=[List() for i in range(701)]
    
        
    def __str__(self):
        """"prints the table"""
        out="{ "
        for i in self.table:
            head=i.head
            while(head!=None):
                out+= str(head.getData()) + " "
                head= head.getNext()
        out += "}"
        return out

    def insert(self, x):
        """maps the element x to slot x"""
        # O(1) worst case running time B)

        self.table[h(x)].push(x)

    def delete(self, x):
        """deletes the element x"""
        # O(n) worst case running time :/
        self.table[h(x)].delete(x)           

    def search(self, k):
        """searches for key k"""
        head=self.table[h(k)].head
        while head!=None:
            # O(n) worst case running time :/
            if head.getData() == k:
                print("Found")
                return None
            head=head.getNext()
        print("Not Found")    

def h(k):
        # hash function
        return k % 701        


a=Table()
a.insert(3)
a.insert(5)
a.insert(37832)
a.insert(0)
print(a)
a.search(5)
a.insert(-5)
a.delete(5)
a.search(5)
print(a)


