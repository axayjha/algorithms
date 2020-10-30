"""
Q2.3: Implement an algorithm to delete a node in the middle (i.e., any node but the first
and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.
Example: 
Input: the node c from the linked list a->b->c->d->e->f
Result: nothing is returned, but the new linked list looks like a->b->d->e->f
"""

def deleteNode(node):
        if not node or not node.next: return False 

        node.val = node.next.val 
        node.next = node.next.next 

        return True
