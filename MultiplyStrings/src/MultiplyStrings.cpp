//============================================================================
// Multiply Strings
//
// Given two numbers represented as strings, return multiplication of the
// numbers as a string.
//
// Note: The numbers can be arbitrarily large and are non-negative.
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int pad(string &num1, string &num2) {
        int M = num1.size();
        int N = num2.size();
        int L = max(M, N);
        for (int i = 0; i < L; i++) {
            if (i >= M) num1 = '0' + num1;
            if (i >= N) num2 = '0' + num2;
        }
        return L;
    }

    string unpad(string num) {
        int N = num.size();
        int i = 0;
        while(i < N && num[i] == '0') i++;
        if (i == N) return "0";
        return num.substr(i, N - i);
    }

    string add(string num1, string num2) {
        int L = pad(num1, num2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res = "";
        int carry = 0;
        for (int i = 0;  i < L; i++) {
            int sum = carry + (num1[i] - '0') + (num2[i] - '0');
            res += ('0' + sum % 10);
            carry = sum / 10;
        }
        if (carry != 0) res.push_back('0' + carry);
        reverse(res.begin(), res.end());
        return res;
    };

    string subtract(string num1, string num2) {
        int L = pad(num1, num2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res = "";
        for (int i = 0; i < L; i++) {
            int diff = num1[i] - num2[i];
            if (diff >= 0) {
                res.push_back('0' + diff);
            }
            else {
                int j = i + 1;
                while (j < L) {
                    num1[j] = '0' + (num1[j] - '0' + 9) % 10;
                    if ((num1[j] - '0') != 9) break;
                    else j++;
                }
                res.push_back('0' + (diff + 10));
            }
        }
        reverse(res.begin(), res.end());
        return res;
    };

    string multiply(string num1, string num2) {
        int L = pad(num1, num2);

        if (L == 1) {
            string res = "";
            int prod = (num1[0] - '0') * (num2[0] - '0');
            if (prod < 10) {
                res.push_back('0' + prod);
                return res;
            }
            res.push_back('0' + prod / 10);
            res.push_back('0' + prod % 10);
            return res;
        }

        int m0 = (L + 1) / 2;
        int m1 = L / 2;
        string x0 = num1.substr(0, m0);
        string x1 = num1.substr(m0, L/2);
        string y0 = num2.substr(0, m0);
        string y1 = num2.substr(m0, L/2);

        string p0 = multiply(x0, y0);
        string p1 = multiply(add(x0, x1), add(y0, y1));
        string p2 = multiply(x1, y1);
        p1 = subtract(p1, add(p0, p2));

        for (int i = 0; i < 2 * m1; i++) p0 += '0';
        for (int i = 0; i < m1; i++) p1 += '0';
        return unpad(add(add(p0, p1), p2));
    };
};

int main() {
    return 0;
}
