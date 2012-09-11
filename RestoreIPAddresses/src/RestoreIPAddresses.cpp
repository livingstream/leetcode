//============================================================================
// Restore IP Addresses
// Given a string containing only digits, restore it by returning all possible
// valid IP address combinations.
//
// For example:
// Given "25525511135",
//
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
//============================================================================

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 4 || s.size() > 12) return res;
        restoreIpAddressesHelper(s, 0, 4, "", res);
        return res;
    }

    void restoreIpAddressesHelper(string &s, size_t i, size_t k, string sol, vector<string> &res) {
        if (k < 0) return;
        if (i == s.size()) {
            if (k == 0) res.push_back(sol);
            return;
        }
        int x = 0;
        size_t j = i;
        while (j < s.size()) {
            x = 10*x+(s[j]-'0');
            if (x > 255) break;
            if (k != 4 && i == j) sol.push_back('.');
            sol.push_back(s[j++]);
            restoreIpAddressesHelper(s, j, k-1, sol, res);
            if (x == 0) break;
        }
    }
};

string printVector(vector<string> v) {
    ostringstream stream;
    stream << "{";
    for (size_t i = 0; i < v.size(); i++) {
         if (i > 0) stream << "," << v[i];
         else stream << v[i];
    }
    stream << "}";
    return stream.str();
};

bool runTest(int testNum, string s, bool hasAnswer, vector<string> result) {
    cout << "Test " << testNum << ": [" << s << "]"<< endl;
    Solution *obj;
    vector<string> answer;
    obj = new Solution();
    clock_t startTime = clock();
    answer = obj->restoreIpAddresses(s);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << printVector(result) << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << printVector(answer) << endl;
    if (hasAnswer) {
        if (!equal(answer.begin(), answer.end(), result.begin())) {
            res = false;
        }
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}

int main() {
    bool all_right;
    all_right = true;
    string s;
    vector<string> result;

    {
        // ----- test 0 -----
        s = "0000";
        string array[] = {"0.0.0.0"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(0, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 1 -----
        s = "1111";
        string array[] = {"1.1.1.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(1, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 2 -----
        s = "010010";
        string array[] = {"0.10.0.10","0.100.1.0"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(2, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 3 -----
        s = "101023";
        string array[] = {"1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(3, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 4 -----
        s = "172162541";
        string array[] = {"17.216.25.41","17.216.254.1","172.16.25.41","172.16.254.1","172.162.5.41","172.162.54.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(4, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 5 -----
        s = "19216811";
        string array[] = {"1.92.168.11","19.2.168.11","19.21.68.11","19.216.8.11","19.216.81.1","192.1.68.11","192.16.8.11","192.16.81.1","192.168.1.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(5, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 6 -----
        s = "25525511135";
        string array[] = {"255.255.11.135","255.255.111.35"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(6, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 7 -----
        s = "255255255255";
        string array[] = {"255.255.255.255"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(7, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 8 -----
        s = "";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(8, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 9 -----
        s = "0";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(9, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 10 -----
        s = "00";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(10, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 11 -----
        s = "000";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(11, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 12 -----
        s = "00000";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(12, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 13 -----
        s = "10101010";
        string array[] = {"10.10.10.10","10.10.101.0","10.101.0.10","101.0.10.10","101.0.101.0"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(13, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 14 -----
        s = "00003";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(14, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 15 -----
        s = "000256";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(15, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 16 -----
        s = "1111111";
        string array[] = {"1.1.11.111","1.1.111.11","1.11.1.111","1.11.11.11","1.11.111.1","1.111.1.11","1.111.11.1","11.1.1.111","11.1.11.11","11.1.111.1","11.11.1.11","11.11.11.1","11.111.1.1","111.1.1.11","111.1.11.1","111.11.1.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(16, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 17 -----
        s = "11111111";
        string array[] = {"1.1.111.111","1.11.11.111","1.11.111.11","1.111.1.111","1.111.11.11","1.111.111.1","11.1.11.111","11.1.111.11","11.11.1.111","11.11.11.11","11.11.111.1","11.111.1.11","11.111.11.1","111.1.1.111","111.1.11.11","111.1.111.1","111.11.1.11","111.11.11.1","111.111.1.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(17, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 18 -----
        s = "111111111";
        string array[] = {"1.11.111.111","1.111.11.111","1.111.111.11","11.1.111.111","11.11.11.111","11.11.111.11","11.111.1.111","11.111.11.11","11.111.111.1","111.1.11.111","111.1.111.11","111.11.1.111","111.11.11.11","111.11.111.1","111.111.1.11","111.111.11.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(18, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 19 -----
        s = "1111111111";
        string array[] = {"1.111.111.111","11.11.111.111","11.111.11.111","11.111.111.11","111.1.111.111","111.11.11.111","111.11.111.11","111.111.1.111","111.111.11.11","111.111.111.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(19, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 20 -----
        s = "123123123";
        string array[] = {"1.23.123.123","1.231.23.123","1.231.231.23","12.3.123.123","12.31.23.123","12.31.231.23","123.1.23.123","123.1.231.23","123.12.3.123","123.12.31.23","123.123.1.23","123.123.12.3"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(20, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 21 -----
        s = "9999999";
        string array[] = {"9.99.99.99","99.9.99.99","99.99.9.99","99.99.99.9"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(21, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 22 -----
        s = "2551234512";
        string array[] = {"255.123.45.12"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(22, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 23 -----
        s = "1231231231234";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(23, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 24 -----
        s = "11111";
        string array[] = {"1.1.1.11","1.1.11.1","1.11.1.1","11.1.1.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(24, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 25 -----
        s = "111111";
        string array[] = {"1.1.1.111","1.1.11.11","1.1.111.1","1.11.1.11","1.11.11.1","1.111.1.1","11.1.1.11","11.1.11.1","11.11.1.1","111.1.1.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(25, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 26 -----
        s = "28576";
        string array[] = {"2.8.5.76","2.8.57.6","2.85.7.6","28.5.7.6"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(26, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 27 -----
        s = "02852";
        string array[] = {"0.2.8.52","0.2.85.2","0.28.5.2"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(27, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 28 -----
        s = "405935087";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(28, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 29 -----
        s = "774094";
        string array[] = {"7.7.40.94","7.74.0.94","77.4.0.94","77.40.9.4"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(29, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 30 -----
        s = "21226991";
        string array[] = {"2.122.69.91","21.22.69.91","21.226.9.91","21.226.99.1","212.2.69.91","212.26.9.91","212.26.99.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(30, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 31 -----
        s = "39777";
        string array[] = {"3.9.7.77","3.9.77.7","3.97.7.7","39.7.7.7"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(31, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 32 -----
        s = "74021";
        string array[] = {"7.4.0.21","7.40.2.1","74.0.2.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(32, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 33 -----
        s = "009973997";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(33, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 34 -----
        s = "103574606193";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(34, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 35 -----
        s = "85737962171";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(35, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 36 -----
        s = "6625338";
        string array[] = {"6.6.253.38","6.62.53.38","66.2.53.38","66.25.3.38","66.25.33.8","66.253.3.8"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(36, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 37 -----
        s = "66212274";
        string array[] = {"6.62.122.74","66.2.122.74","66.21.22.74","66.21.227.4","66.212.2.74","66.212.27.4"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(37, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 38 -----
        s = "3420479551";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(38, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 39 -----
        s = "240102";
        string array[] = {"2.4.0.102","2.40.10.2","24.0.10.2","240.1.0.2"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(39, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 40 -----
        s = "5891453778";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(40, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 41 -----
        s = "3320526411";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(41, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 42 -----
        s = "384";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(42, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 43 -----
        s = "870365156";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(43, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 44 -----
        s = "0279245587303";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(44, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 45 -----
        s = "149654651";
        string array[] = {"149.65.46.51"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(45, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 46 -----
        s = "893142";
        string array[] = {"8.9.3.142","8.9.31.42","8.93.1.42","8.93.14.2","89.3.1.42","89.3.14.2","89.31.4.2"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(46, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 47 -----
        s = "648884";
        string array[] = {"6.4.88.84","6.48.8.84","6.48.88.4","64.8.8.84","64.8.88.4","64.88.8.4"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(47, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 48 -----
        s = "52282785";
        string array[] = {"5.228.27.85","52.28.27.85"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(48, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 49 -----
        s = "72830678661";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(49, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 50 -----
        s = "339997";
        string array[] = {"3.3.99.97","3.39.9.97","3.39.99.7","33.9.9.97","33.9.99.7","33.99.9.7"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(50, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 51 -----
        s = "914536573";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(51, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 52 -----
        s = "2736786374048";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(52, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 53 -----
        s = "739858841";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(53, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 54 -----
        s = "1697";
        string array[] = {"1.6.9.7"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(54, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 55 -----
        s = "4253741";
        string array[] = {"4.25.37.41","4.253.7.41","4.253.74.1","42.5.37.41","42.53.7.41","42.53.74.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(55, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 56 -----
        s = "0457497680575";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(56, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 57 -----
        s = "7269340075";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(57, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 58 -----
        s = "582910";
        string array[] = {"5.8.29.10","5.82.9.10","5.82.91.0","58.2.9.10","58.2.91.0","58.29.1.0"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(58, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 59 -----
        s = "6602";
        string array[] = {"6.6.0.2"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(59, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 60 -----
        s = "796";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(60, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 61 -----
        s = "65522";
        string array[] = {"6.5.5.22","6.5.52.2","6.55.2.2","65.5.2.2"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(61, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 62 -----
        s = "01154341";
        string array[] = {"0.115.43.41"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(62, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 63 -----
        s = "993033";
        string array[] = {"9.9.30.33","9.93.0.33","99.3.0.33","99.30.3.3"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(63, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 64 -----
        s = "914392272127";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(64, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 65 -----
        s = "67570233744";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(65, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 66 -----
        s = "6719058";
        string array[] = {"6.7.190.58","6.71.90.58","67.1.90.58","67.19.0.58","67.190.5.8"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(66, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 67 -----
        s = "13538";
        string array[] = {"1.3.5.38","1.3.53.8","1.35.3.8","13.5.3.8"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(67, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 68 -----
        s = "796542411445";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(68, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 69 -----
        s = "3913584611";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(69, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 70 -----
        s = "73028846703";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(70, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 71 -----
        s = "47451008";
        string array[] = {"47.45.100.8"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(71, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 72 -----
        s = "22972";
        string array[] = {"2.2.9.72","2.2.97.2","2.29.7.2","22.9.7.2"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(72, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 73 -----
        s = "459022042";
        string array[] = {"45.90.220.42"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(73, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 74 -----
        s = "887";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(74, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 75 -----
        s = "104";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(75, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 76 -----
        s = "70972034";
        string array[] = {"70.97.20.34","70.97.203.4"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(76, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 77 -----
        s = "44610202";
        string array[] = {"4.46.10.202","44.6.10.202","44.61.0.202"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(77, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 78 -----
        s = "459759532";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(78, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 79 -----
        s = "5672";
        string array[] = {"5.6.7.2"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(79, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 80 -----
        s = "9239773";
        string array[] = {"9.23.97.73","9.239.7.73","9.239.77.3","92.3.97.73","92.39.7.73","92.39.77.3"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(80, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 81 -----
        s = "3923156";
        string array[] = {"3.9.23.156","3.9.231.56","3.92.3.156","3.92.31.56","39.2.3.156","39.2.31.56","39.23.1.56","39.23.15.6","39.231.5.6"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(81, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 82 -----
        s = "937686";
        string array[] = {"9.3.76.86","9.37.6.86","9.37.68.6","93.7.6.86","93.7.68.6","93.76.8.6"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(82, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 83 -----
        s = "1039";
        string array[] = {"1.0.3.9"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(83, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 84 -----
        s = "2171522";
        string array[] = {"2.17.15.22","2.17.152.2","2.171.5.22","2.171.52.2","21.7.15.22","21.7.152.2","21.71.5.22","21.71.52.2","217.1.5.22","217.1.52.2","217.15.2.2"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(84, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 85 -----
        s = "253578103984";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(85, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 86 -----
        s = "530474625546";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(86, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 87 -----
        s = "647";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(87, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 88 -----
        s = "69625508557";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(88, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 89 -----
        s = "1914";
        string array[] = {"1.9.1.4"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(89, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 90 -----
        s = "71743290146";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(90, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 91 -----
        s = "2611438956";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(91, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 92 -----
        s = "2514428822";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(92, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 93 -----
        s = "6787";
        string array[] = {"6.7.8.7"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(93, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 94 -----
        s = "925444778";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(94, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 95 -----
        s = "686431045685";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(95, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 96 -----
        s = "09069048";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(96, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 97 -----
        s = "86520218";
        string array[] = {"8.65.20.218","8.65.202.18","86.5.20.218","86.5.202.18","86.52.0.218"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(97, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 98 -----
        s = "98441567";
        string array[] = {"98.44.15.67","98.44.156.7"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(98, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 99 -----
        s = "2679891";
        string array[] = {"2.67.98.91","26.7.98.91","26.79.8.91","26.79.89.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(99, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 100 -----
        s = "8118294";
        string array[] = {"8.1.182.94","8.11.82.94","8.118.2.94","8.118.29.4","81.1.82.94","81.18.2.94","81.18.29.4","81.182.9.4"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(100, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 101 -----
        s = "3636";
        string array[] = {"3.6.3.6"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(101, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 102 -----
        s = "965329888";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(102, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 103 -----
        s = "249";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(103, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 104 -----
        s = "304005";
        string array[] = {"30.40.0.5"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(104, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 105 -----
        s = "99458742513";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(105, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 106 -----
        s = "865763";
        string array[] = {"8.6.57.63","8.65.7.63","8.65.76.3","86.5.7.63","86.5.76.3","86.57.6.3"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(106, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 107 -----
        s = "88291";
        string array[] = {"8.8.2.91","8.8.29.1","8.82.9.1","88.2.9.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(107, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 108 -----
        s = "0690";
        string array[] = {"0.6.9.0"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(108, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 109 -----
        s = "21369353";
        string array[] = {"2.136.93.53","21.36.93.53","213.6.93.53","213.69.3.53","213.69.35.3"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(109, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 110 -----
        s = "1402488263063";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(110, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 111 -----
        s = "652811844292";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(111, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 112 -----
        s = "38429053433";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(112, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 113 -----
        s = "078";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(113, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 114 -----
        s = "2547";
        string array[] = {"2.5.4.7"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(114, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 115 -----
        s = "20037656";
        string array[] = {"200.3.76.56","200.37.6.56","200.37.65.6"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(115, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 116 -----
        s = "61904";
        string array[] = {"6.1.90.4","6.19.0.4","61.9.0.4"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(116, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 117 -----
        s = "2916455645560";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(117, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 118 -----
        s = "6926";
        string array[] = {"6.9.2.6"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(118, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 119 -----
        s = "73822";
        string array[] = {"7.3.8.22","7.3.82.2","7.38.2.2","73.8.2.2"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(119, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 120 -----
        s = "8380982";
        string array[] = {"83.80.9.82","83.80.98.2"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(120, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 121 -----
        s = "00377933";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(121, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 122 -----
        s = "156";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(122, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 123 -----
        s = "706";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(123, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 124 -----
        s = "7199";
        string array[] = {"7.1.9.9"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(124, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 125 -----
        s = "199998";
        string array[] = {"1.9.99.98","1.99.9.98","1.99.99.8","19.9.9.98","19.9.99.8","19.99.9.8","199.9.9.8"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(125, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 126 -----
        s = "392329";
        string array[] = {"3.9.23.29","3.9.232.9","3.92.3.29","3.92.32.9","39.2.3.29","39.2.32.9","39.23.2.9"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(126, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 127 -----
        s = "3460536306";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(127, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 128 -----
        s = "1321";
        string array[] = {"1.3.2.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(128, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 129 -----
        s = "64373453747";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(129, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 130 -----
        s = "86540";
        string array[] = {"8.6.5.40","8.6.54.0","8.65.4.0","86.5.4.0"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(130, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 131 -----
        s = "487219021";
        string array[] = {"48.72.190.21"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(131, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 132 -----
        s = "64948";
        string array[] = {"6.4.9.48","6.4.94.8","6.49.4.8","64.9.4.8"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(132, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 133 -----
        s = "1387973612576";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(133, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 134 -----
        s = "225948962";
        string array[] = {"225.94.89.62"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(134, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 135 -----
        s = "1980";
        string array[] = {"1.9.8.0"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(135, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 136 -----
        s = "665144";
        string array[] = {"6.6.5.144","6.6.51.44","6.65.1.44","6.65.14.4","66.5.1.44","66.5.14.4","66.51.4.4"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(136, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 137 -----
        s = "37941";
        string array[] = {"3.7.9.41","3.7.94.1","3.79.4.1","37.9.4.1"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(137, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 138 -----
        s = "37161977";
        string array[] = {"37.16.19.77","37.16.197.7","37.161.9.77","37.161.97.7"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(138, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 139 -----
        s = "63004186442";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(139, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 140 -----
        s = "885";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(140, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 141 -----
        s = "15786116";
        string array[] = {"1.57.86.116","15.7.86.116","15.78.6.116","15.78.61.16","157.8.6.116","157.8.61.16","157.86.1.16","157.86.11.6"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(141, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 142 -----
        s = "97475150";
        string array[] = {"9.74.75.150","97.4.75.150","97.47.5.150","97.47.51.50"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(142, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 143 -----
        s = "656631164";
        string array[] = {"65.66.31.164"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(143, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 144 -----
        s = "629079832117";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(144, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 145 -----
        s = "1308758";
        string array[] = {"1.30.87.58","13.0.87.58","130.8.7.58","130.8.75.8","130.87.5.8"};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(145, s, true, result) && all_right;
        // ------------------
    }
    {
        // ----- test 146 -----
        s = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
        string array[] = {};
        result.assign(array, array + sizeof(array) / sizeof(array[0]));
        all_right = runTest(146, s, true, result) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
