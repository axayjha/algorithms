"""
Q2.2: Implement an algorithm to find the kth to last element of a singly linked list.
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

# by knowing the length first
def kth_to_last(head, k):
        n = 0
        temp = head 
        while temp:
                n += 1
                temp = temp.next 
        k = n - k 
        temp = head
        while k > 0:
                k -= 1
                temp = temp.next 
        print(temp.val)                

# kth_to_last(head, 2)

# recursive approach
# can only print data and not return node
def kth_to_last1(head, k):
        if head == None: return 0
        index = kth_to_last1(head.next, k) + 1
        if index == k:
                print(head.val)
        return index

# kth_to_last1(head, 1)                        

# recursive approach with static counter var
# can return node
def kth_to_last2(head, k):
        if head == None: return None
        node = kth_to_last2(head.next, k)
        kth_to_last2.index += 1
        if kth_to_last2.index == k:
                return head
        return node

kth_to_last2.index = 0
print(kth_to_last2(head, 1).val)   