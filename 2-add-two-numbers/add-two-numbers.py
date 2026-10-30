# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        #non empty linked list and non negative and digit is stored in reversed order
        dummy =ListNode()
        curr =dummy
        carry =0

        while l1 or l2 or carry:
            v1=l1.val if l1 else 0
            v2=l2.val if l2 else 0
            # new digit
            val=v1 +v2+carry
            carry=val//10
            val=val%10
            curr.next=ListNode(val)

            #update pointer
            curr=curr.next
            l1=l1.next if l1 else None
            l2=l2.next if l2 else None # mistake was l2 is update by l1
        # or carry handle cases like 7 + 8  to 1->5
        
        return dummy.next