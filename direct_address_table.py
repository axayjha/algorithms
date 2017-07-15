## Direct Address Table implementation
##
## Akshay
## 15/07/2017


class Table(object):   
    """
        Direct Address Table implementation        
        *Stores only ints*
    """
    def __init__(self, data=None, Range=1000):
        """
            //CONSTRUCTOR
            
            *Params are optional*
            data should be a list in the param.
            Range should be a positive integer. Better leave that alone.
        """
        if(type(data)==list):
            self.data=[None for i in range(Range)]
            for i in data:
                self.data[i] = i
        elif (data==None):
            self.data=[None for i in range(Range)]
        else:
            raise TypeError("Invalid input param")
        
    def __str__(self):
        """"prints the table"""
        out="{ "
        if self.data!=None:            
            for i in self.data:
                if i is not None:
                    out += (str(i) + " ")
            out += "}"
            return out
        return "{ }"

    def insert(self, x):
        """maps the element x to slot x"""
        try:
            self.data[x] = x
        except:
            print("key out of range")

    def delete(self, x):
        """deletes the element x"""
        try:
            self.data[x] = None
        except:
            print("key out of range")            

    def search(self, k):
        """searches for key k"""
        try:
            print("Found")
            return self.data[k]
        except:
            print("Not Found")
            
        

