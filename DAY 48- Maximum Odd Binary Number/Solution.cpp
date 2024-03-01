class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        //create char array
        const int N = s.length(); 
        char* arr = new char[N + 1]; 
        strcpy(arr, s.c_str()); 

        sort(arr, arr+N);

        // Reverse order for the first N - 1 elements of the array
        // Because we want to keep a 1 at the last index
        // The last element of the array is index N - 1, and the second to last is at N - 2
        int secondLast = N - 2;
        for (int i = 0; i < N / 2; i++) {
            char temp = arr[i];
            arr[i] = arr[secondLast - i];
            arr[secondLast - i] = temp;
        }

        // Return result
        return arr;
    }
};
