"""
Q2.4: Write code to partition a linked list around a value x, such that all nodes
less than x come before all nodes greater than or equal to x. If x is contained within the list,
the values of x only need to be after the elements less than x (see below). The partition
element x can appear anywhere in the "right partition"; it does not need to appear between
the left and right partition.

EXAMPLE
Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 ->1 [partition = 5]
Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
"""


class Node:
        def __init__(self, val):
                self.data = val 
                self.next = None

def display(head):
        temp = head 
        while temp:
                print(temp.data, end=" ")
                temp = temp.next 
        print()             


head = Node(3)
head.next = Node(4)
head.next.next = Node(3)
head.next.next.next = Node(5)
head.next.next.next.next = Node(6)


# stable
def partition(node, x):
        # smaller half of list
        beforeStart = None
        beforeEnd = None
        # larger half of list
        afterStart = None 
        afterEnd = None 

        while node:
                nxt = node.next
                node.next = None 

                if node.data < x :
                        if beforeStart == None:
                                beforeStart = node 
                                beforeEnd = beforeStart
                        else:
                                beforeEnd.next = node 
                                beforeEnd = node 
                else:
                        if afterStart == None:
                                afterStart = node    
                                afterEnd = afterStart
                        else:
                                afterEnd.next = node 
                                afterEnd = node  
                node = nxt 

        if beforeStart == None:
                return afterStart

        beforeEnd.next = afterStart
        return beforeStart                                                                                       


# display(head)
# n = partition(head, 4)
# display(n)


def partition1(node, x):
        head = node
        tail = node 

        while node:
                nxt = node.next 
                if node.data < x:
                        node.next = head 
                        head = node
                else:
                        tail.next = node
                        tail = node
                node = nxt 

        tail.next = None 
        return head 

display(head)
n = partition1(head, 4)
display(n)

