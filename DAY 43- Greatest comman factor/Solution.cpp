#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int numElements = nums.size();
        if (numElements == 1) return true;

        vector<int> disjointSet(numElements);
        vector<int> setSize(numElements, 1);
        unordered_map<int, int> factorFirstOccurrence;

        for (int i = 0; i < numElements; ++i) {
            disjointSet[i] = i;
            int num = nums[i];
            int divisor = 2;
            while (divisor * divisor <= num) {
                if (num % divisor == 0) {
                    if (factorFirstOccurrence.find(divisor) != factorFirstOccurrence.end()) {
                        unionSets(disjointSet, setSize, i, factorFirstOccurrence[divisor]);
                    } else {
                        factorFirstOccurrence[divisor] = i;
                    }
                    while (num % divisor == 0) {
                        num /= divisor;
                    }
                }
                divisor++;
            }
            if (num > 1) {
                if (factorFirstOccurrence.find(num) != factorFirstOccurrence.end()) {
                    unionSets(disjointSet, setSize, i, factorFirstOccurrence[num]);
                } else {
                    factorFirstOccurrence[num] = i;
                }
            }
        }

        return setSize[findSetLeader(disjointSet, 0)] == numElements;
    }

private:
    int findSetLeader(vector<int>& disjointSet, int x) {
        if (disjointSet[x] == x) return x;
        disjointSet[x] = findSetLeader(disjointSet, disjointSet[x]);
        return disjointSet[x];
    }

    void unionSets(vector<int>& disjointSet, vector<int>& setSize, int x, int y) {
        int xLeader = findSetLeader(disjointSet, x);
        int yLeader = findSetLeader(disjointSet, y);
        if (xLeader == yLeader) return;
        if (setSize[xLeader] < setSize[yLeader]) {
            disjointSet[xLeader] = yLeader;
            setSize[yLeader] += setSize[xLeader];
        } else {
            disjointSet[yLeader] = xLeader;
            setSize[xLeader] += setSize[yLeader];
        }
    }
};





