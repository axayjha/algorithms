"""
Q2.8: Given a circular linked list, implement an algorithm that returns the node at the
beginning of the loop.
EXAMPLE
Input: A -> B -> C -> D -> E -> C (the same C as earlier)
Output: C
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

l1 = Node(3)
l1.next = Node(1)
l1.next.next = Node(5)
l1.next.next.next = Node(7)
l1.next.next.next.next = Node(7)
l1.next.next.next.next.next = Node(2)
l1.next.next.next.next.next.next = l1.next.next 

def detect_rotation(head):
        slow = head 
        fast = head 

        while fast and fast.next:
                slow = slow.next
                fast = fast.next.next 
                if slow == fast:
                        break
        if not fast or not fast.next:
                print("No rotation")
                return  

        slow = head 

        while slow != fast:
                slow = slow.next
                fast = fast.next 
        print("Rotation starts from node: "+ str(fast.data))
        return                               

detect_rotation(l1)