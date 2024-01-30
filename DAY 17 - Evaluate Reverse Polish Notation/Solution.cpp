class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> numbers;

        for (const string& token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                numbers.push(stoi(token));
            } else { /
                int operand2 = numbers.top();
                numbers.pop();

                int operand1 = numbers.top();
                numbers.pop();

                // Perform the operation based on the type of operator
                switch (token[0]) {
                    case '+': // Addition
                        numbers.push(operand1 + operand2);
                        break;
                    case '-': // Subtraction
                        numbers.push(operand1 - operand2);
                        break;
                    case '*': // Multiplication
                        numbers.push(operand1 * operand2);
                        break;
                    case '/': // Division
                        numbers.push(operand1 / operand2);
                        break;
                }                
            }
        }

        // The final result is the only number remaining on the stack
        return numbers.top();
    }
};
