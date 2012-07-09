//============================================================================
// Find the contiguous subarray within an array (containing at least one
// number) which has the largest sum.
//
// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
// the contiguous subarray [4,−1,2,1] has the largest sum = 6.
//============================================================================

class Solution {
public:
    int maxSubArray(int A[], int n) {
        bool allNegative = true;
        int maxElem = A[0];
        for (int i = 0; i < n; i++) {
            if (A[i] > 0) {
                allNegative = false;
                break;
            }
            if (A[i] > maxElem) maxElem = A[i];
        }
        if (allNegative) return maxElem;

        int maxEndHere = 0;
        int maxSoFar = 0;
        for (int i = 0; i < n; i++) {
            maxEndHere += A[i];
            if (maxEndHere < 0) maxEndHere = 0;
            if (maxEndHere > maxSoFar)  maxSoFar = maxEndHere;
        }
        return maxSoFar;
    }
};

int main() {
    return 0;
}
