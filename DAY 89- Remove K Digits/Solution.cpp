class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::stack<char> stack;
        
        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.top() > digit) {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }
        
        // Remove remaining k digits from the end of the stack
        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }
        
        // Construct the resulting string from the stack
        std::string result;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        std::reverse(result.begin(), result.end()); // Reverse to get the correct order
        
        // Remove leading zeros
        size_t pos = result.find_first_not_of('0');
        result = (pos == std::string::npos) ? "0" : result.substr(pos);
        
        return result;
    }
};
