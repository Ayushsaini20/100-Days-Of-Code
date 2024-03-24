## Reorder List
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:

<img width="507" alt="Screenshot 2024-03-24 at 10 20 06 PM" src="https://github.com/Ayushsaini20/100-Days-Of-Code/assets/73630171/a4a763ca-c900-4f36-8932-9df8b9443d05">

Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:

<img width="507" alt="Screenshot 2024-03-24 at 10 20 24 PM" src="https://github.com/Ayushsaini20/100-Days-Of-Code/assets/73630171/4ac0ef31-3dd6-4cca-baa2-16f15c46e265">

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
