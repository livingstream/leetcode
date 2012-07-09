//============================================================================
// 4Sum
// Given an array S of n integers, are there elements a, b, c, and d in S such
// that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.
// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order.
// (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
// For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
// A solution set is:
// (-1,  0, 0, 1)
// (-2, -1, 1, 2)
// (-2,  0, 0, 2)
//============================================================================

#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

struct TwoSum{
public:
    TwoSum(int idx1, int idx2, int v) :
        index1(idx1), index2(idx2), value(v) {}
public:
    int index1;
    int index2;
    int value;
};

struct TwoSumCompare {
    bool operator() (TwoSum ts1, TwoSum ts2) {
        if (ts1.value == ts2.value){
            if (ts1.index1 == ts1.index1) return (ts1.index2 < ts2.index2);
            else return (ts1.index1 < ts2.index1);
        }
        else
            return (ts1.value < ts2.value);
    }
} twoSumCompare;

class Solution {
private:
    vector<vector<int> > result;
    vector<TwoSum> twoSum;

public:
    int find_start_index(int begin, int end, int val){
        int mid;
        while (begin <= end){
            mid = begin + (end - begin) / 2;
            if (twoSum[mid].value >= val) end = mid - 1;
            else begin = mid + 1;
        }
        return end + 1;
    }

    int find_end_index(int begin, int end, int val){
        int mid;
        while (begin <= end){
            mid = begin + (end - begin) / 2;
            if (twoSum[mid].value <= val) begin = mid + 1;
            else end = mid - 1;
        }
        return begin - 1;
    }

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        twoSum.clear();
        result.clear();
        size_t i, j;
        for (i = 0; i < num.size(); i++){
            for (j=i + 1; j < num.size(); j++){
                TwoSum ts(i, j, num[i] + num[j]);
                twoSum.push_back(ts);
            }
        }
        sort(twoSum.begin(), twoSum.end(), twoSumCompare);
        for (i = 0; i < twoSum.size(); i++){
            size_t begin, end;
            int val = target - twoSum[i].value;

            begin = find_start_index(i + 1, twoSum.size() - 1, val);
            end = find_end_index(i + 1, twoSum.size() - 1, val);

            for (j = begin; j <= end; j++){
                if (twoSum[j].index1 == twoSum[i].index1) continue;
                if (twoSum[j].index2 == twoSum[i].index1) continue;
                if (twoSum[j].index1 == twoSum[i].index2) continue;
                if (twoSum[j].index2 == twoSum[i].index2) continue;

                vector<int> tmp;
                tmp.push_back(num[ twoSum[i].index1]);
                tmp.push_back(num[ twoSum[i].index2]);
                tmp.push_back(num[ twoSum[j].index1]);
                tmp.push_back(num[ twoSum[j].index2]);

                sort(tmp.begin(), tmp.end());

                if (find(result.begin(), result.end(), tmp) == result.end())
                    result.push_back(tmp);
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
