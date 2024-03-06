## Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:

<img width="186" alt="image" src="https://github.com/Ayushsaini20/100-Days-Of-Code/assets/73630171/4fbf852b-2075-49a8-8ddf-44d5fa1ed9bb">

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:

<img width="107" alt="image" src="https://github.com/Ayushsaini20/100-Days-Of-Code/assets/73630171/5fef7c4e-5dee-464f-ba3b-2a83f76277db">

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:


<img width="37" alt="image" src="https://github.com/Ayushsaini20/100-Days-Of-Code/assets/73630171/d5b27105-0d11-4c71-ac5b-4b32c52307d5">


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
