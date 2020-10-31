"""
Q2.5: You have two numbers represented by a linked list, where each node contains a single digit.
The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write
a function that adds the two numbers and returns the sum as a linked list.

EXAMPLE
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
Output: 2 -> 1 -> 9. That is, 912

FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
Output: 9 -> 1 -> 2. That is, 912.
"""


class Node:
        def __init__(self, val=0):
                self.data = val 
                self.next = None

def display(head):
        temp = head 
        while temp:
                print(temp.data, end=" ")
                temp = temp.next 
        print()             


l1 = Node(7)
l1.next = Node(1)
l1.next.next = Node(6)

l2 = Node(4)
l2.next = Node(8)
l2.next.next = Node(3)


def add_lists(l1, l2):
        result = None 
        ans = None
        carry = 0
        while l1 or l2:
                s = 0
                if l1:
                        s += l1.data 
                if l2:
                        s += l2.data
                s += carry 
                if s >= 10:
                        carry = s//10 
                        s = s%10
                else: 
                        carry = 0    
                                            
                if result == None:
                        result = Node(s)
                        ans = result
                else:
                        result.next = Node(s)
                        result = result.next
                if l1:
                        l1 = l1.next
                if l2:        
                        l2 = l2.next                        
        if carry != 0:
                result.next = Node(carry)
        return ans                 

                                                                                                                        
# n = add_lists(l1, l2)
# display(n)


def reverse_list(head):
        if not head.next: return head
        start = head 
        curr = head.next 
        temp = None
        while curr:
                temp = curr.next
                curr.next = start
                start = curr 
                curr = temp
        head.next = None       
        return start 

                     
"""
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
Output: 9 -> 1 -> 2. That is, 912.
"""

def add_lists1(l1, l2):
        l1 = reverse_list(l1)
        l2 = reverse_list(l2)
        l3 = add_lists(l1, l2)
        return reverse_list(l3)


l1 = Node(6)
l1.next = Node(1)
l1.next.next = Node(7)

l2 = Node(2)
l2.next = Node(9)
l2.next.next = Node(5)
l2.next.next.next = Node(0)

display(add_lists1(l1, l2))

#-------------Correct approach below-------


l1 = Node(9)
l1.next = Node(9)
l1.next.next = Node(9)
# l1.next.next.next = Node(2)

l2 = Node(2)
# l2.next = Node(2)
# l2.next.next = Node(9)

def add_lists2(l1, l2):
        result = Node()
        carry = 0
        def add_lists_samesize(l1, l2):
                nonlocal carry
                if l1 == None: 
                        # since both lists are supposed to be same size
                        return None
                summ = 0
                result = Node()
                
                result.next = add_lists_samesize(l1.next, l2.next)

                summ = l1.data + l2.data + carry
                carry  = summ//10
                summ = summ%10

                result.data = summ 

                return result

        def push(head, val):
                node = Node(val)
                node.next = head
                return node

        def getSize(l1):
                n = 0
                while l1:
                        n += 1
                        l1 = l1.next
                return n                        

        def add_to_remaining(l1, cur):
                nonlocal carry
                nonlocal result
                if l1 != cur :
                        add_to_remaining(l1.next, cur)

                        summ = l1.data + carry
                        carry = summ//10
                        summ %= 10

                        result = push(result, summ)

        if l1 == None:
                return l2 

        if l2 == None:
                return l1 

        n1 = getSize(l1)
        n2 = getSize(l2)
        

        head1 = None
        head2 = None

        if n1 == n2:
                result =  add_lists_samesize(l1, l2)    
        else:
                diff = abs(getSize(l1)-getSize(l2))

                if n1 > n2:
                        head1 = l1 
                        head2 = l2 
                else:
                        head1 = l2
                        head2 = l1
                cur = head1
                while diff:
                        cur = cur.next 
                        diff -= 1
                result =  add_lists_samesize(cur, head2)
                add_to_remaining(head1, cur)
        if carry:
                result = push(result, carry)

        return result

display(add_lists2(l1, l2))