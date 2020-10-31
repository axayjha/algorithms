"""
Q2.7: Given two singly linked lists, determine if the two lists intersect. Return the intersecting node. 
Note that the intersection is defined based on reference, not value. That is, if the kth node
of the first linked list is the exact same node (by reference) as the jth node of the second linked list, 
then they are intersecting
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
l1.next.next.next.next.next.next = Node(1)

l2 = Node(4)
l2.next = Node(6)
l2.next.next = l1.next.next.next.next


def intersecting_point(l1, l2):
        len1 = 0
        len2 = 0

        temp1 = l1 
        while temp1:
                len1 += 1
                temp1 = temp1.next

        temp1 = l2 
        while temp1:
                len2 += 1
                temp1 = temp1.next 

        if len1 < len2:
                temp = l1 
                l1 = l2 
                l2 = temp 
        # made l1 longer

        k = abs(len1-len2)
        while k > 0:
                l1 = l1.next 
                k -= 1

        while l1 and l2:
                if id(l1)==id(l2):
                        print("Intersection point found: " + str(l1.data) )
                        return 
                l1 = l1.next 
                l2 = l2.next 
        print("No intersection point found.")                
        return 

intersecting_point(l1, l2)        



