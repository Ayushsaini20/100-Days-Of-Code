## Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.

 

Example 1:

<img width="189" alt="image" src="https://github.com/Ayushsaini20/100-Days-Of-Code/assets/73630171/716f6124-995e-489f-a70e-c2418dd9f1fc">


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

<img width="194" alt="image" src="https://github.com/Ayushsaini20/100-Days-Of-Code/assets/73630171/67e1f88c-4255-443f-82bf-1f371f021ab6">

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:

<img width="193" alt="image" src="https://github.com/Ayushsaini20/100-Days-Of-Code/assets/73630171/aa695d74-d9de-40c9-a565-a6ae279f50ca">

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
