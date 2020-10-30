"""
Q2.1: Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve the problem if a temporary buffer is not allowed?
"""

class Node:
        def __init__(self, val):
                self.val = val 
                self.next = None

def display(head):
        temp = head 
        while temp:
                print(temp.val, end=" ")
                temp = temp.next 
        print()             


head = Node(3)
head.next = Node(4)
head.next.next = Node(3)
head.next.next.next = Node(5)

display(head)

# O(n) time but with O(n) space
def remove_dups(head):
        from collections import defaultdict
        d = defaultdict(bool)
        n = head
        d[head.val] = True 
        while n.next:
                if d[n.next.val]:
                        n.next = n.next.next
                else: 
                        d[n.next.val] = True
                        n = n.next


# remove_dups(head)
# display(head)

# O(n**2) time but O(1) space
def remove_dups1(head):
        n = head 
        while n:
                runner = n
                while runner.next:
                        if n.val == runner.next.val:
                                runner.next = runner.next.next 
                        else:
                                runner = runner.next    
                n = n.next   


remove_dups1(head)
display(head)
