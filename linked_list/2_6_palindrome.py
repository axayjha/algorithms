"""
Q2.6: Implement a function to check if a linked list is a palindrome.
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

head = Node(0)
head.next = Node(1)
head.next.next = Node(3)
head.next.next.next = Node(1)
head.next.next.next.next = Node(0)

def isPalindrome(head):
        a = []
        slow = head
        fast = head 
        while fast and fast.next:
                a.append(slow.data)
                slow = slow.next 
                fast = fast.next.next

        if fast:
                slow = slow.next 
        while slow:
                if slow.data != a.pop():
                        return False 
                slow = slow.next 
        return True                                                        

print(isPalindrome(head))        