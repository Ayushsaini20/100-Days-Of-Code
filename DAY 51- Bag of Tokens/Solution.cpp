class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if (tokens.empty()) return 0;
        sort(tokens.begin(), tokens.end());
        if (power < tokens[0]) return 0;
        
        int score = 1;
        power -= tokens[0];

        int i = 1, j = tokens.size() - 1;
        int maxScore = score;
        while ((score > 0 || power >= tokens[i]) && i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                score += 1;
                i++;
            } 
            else if (score >= 1) {
                power += tokens[j];
                score -= 1;
                j--;
            }
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};
