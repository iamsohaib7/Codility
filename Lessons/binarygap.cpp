// https://app.codility.com/programmers/lessons/1-iterations/binary_gap/
// solution report: https://app.codility.com/demo/results/trainingGF5ERW-DY6/
#include<bits/stdc++.h>
using namespace std;

// Binary Gap Problem:
// The task is to find the longest sequence of zeros in the binary representation
// of a given positive integer that is surrounded by ones. This sequence is called
// a "Binary Gap". For example:
// - The number 20 in binary is 10100. It has one binary gap of length 1.
// - The number 1041 in binary is 1000010001. It has a maximum binary gap of length 5.

// The function `solution` aims to find and return the length of the longest binary gap.
int solution(int num){
    // `cnt` will keep track of the length of the current sequence of zeros.
    int cnt = 0;
    // `ans` will store the maximum length of zero sequences found.
    int ans = 0;
    // `flag` will be used to check if the sequence of zeros is surrounded by ones.
    bool flag = false;

    // Loop until all bits are checked.
    while(num != 0){
        // If the least significant bit is 1...
        if(num & 1){
            // ...and if we have already found a starting one before (`flag` is true)...
            if (flag == true){
                // ...then update the maximum (`ans`) with the current count (`cnt`) if it's larger.
                ans = max(ans, cnt);
            }
            // Reset for the next sequence of zeros.
            flag = true; // We found a 1, so we might have a gap starting.
            cnt = 0; // Reset the zero count.
        }
        else {
            // If the bit is 0 and we have found a starting one, count the zero.
            cnt++;
        }
        // Right shift the number to check the next bit.
        num >>= 1;
    }
    // Return the length of the longest binary gap found.
    return ans;
}

int main(){
    // Example usage of the function with the number 20.
    int num = 20;

    // The `solution` function is called with `num` and the result is stored in `maxBinaryGap`.
    int maxBinaryGap = solution(num);

    // Output the result.
    cout << "Solution: " << maxBinaryGap << endl; // Should output 1 for number 20.
    return 0;
}

