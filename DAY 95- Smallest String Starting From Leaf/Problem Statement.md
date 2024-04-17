## Smallest String Starting From Leaf

You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.


<img width="298" alt="image" src="https://github.com/Ayushsaini20/100-Days-Of-Code/assets/73630171/35aab02e-b528-4065-b312-481eeda661fe">

Input: root = [0,1,2,3,4,3,4]
Output: "dba"

<img width="304" alt="image" src="https://github.com/Ayushsaini20/100-Days-Of-Code/assets/73630171/13d87205-8012-4c54-971f-1d1ada106e01">

Input: root = [25,1,3,1,3,0,2]
Output: "adz"

<img width="268" alt="image" src="https://github.com/Ayushsaini20/100-Days-Of-Code/assets/73630171/2abc3a12-f3c9-4751-b800-6fec27dca383">

Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"


Constraints:

The number of nodes in the tree is in the range [1, 8500].
0 <= Node.val <= 25
