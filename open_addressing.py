## Open Addressing Table implementation
##
## Akshay
## 16/07/2017


class Table(object):   
    """
        Open Addressing Table implementation        
        *Stores only ints*
    """
    def __init__(self):
        """
            //CONSTRUCTOR
        """
        self.data=[None for i in range(701)]
        
    def __str__(self):
        """"prints the table"""
        out="{ "
        for i in self.data:
            if i!="Deleted":
                if i==None:
                    continue
                out += (str(i)+" ")
        out += "}"
        return out
        

    def insert(self, k):
        """maps the element x to slot x"""
        i=0
        while i!=701:
            j=h(k,i)
            if self.data[j] == None :
                self.data[j]=k
                return None
            else:
                i += 1
        print("Hash Table overflow")        

    def delete(self, x):
        """deletes the element x"""
        try:
            self.data[x] = "Deleted"
        except:
            print("key out of range")            

    def search(self, k):
        """searches for key k"""
        i=0
        while(self.data[j] != None or i!=m):
            j=h(k,i)
            if self.data[j] == k:
                print("Found")
                return None
            i+=1
        print("Not Found")  
            
        

def h(k,i):
    return linear_probing(k,i)

def linear_probing(k,i):
    return (k%7 + i) % 701

def quadratic_probing(k,i):
    return ((k%7) + i**2)%701

def double_hashing(k,i):
    return ((k%701) + i*(k%7))%701
