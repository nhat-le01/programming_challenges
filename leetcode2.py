def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        traversal1 = l1
        traversal2 = l2
        dummy = head = ListNode(0)
        carry = 0
        while traversal1 != None or traversal2 != None or carry != 0:
            if traversal1:
                carry += traversal1.val
                traversal1 = traversal1.next
            if traversal2:
                carry += traversal2.val
                traversal2 = traversal2.next
            head.next = ListNode(carry % 10)
            head = head.next
            carry = carry / 10
        return dummy.next
