// Taken from Lintcode
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
/**
 * Following Neetcode's solution:
 * 1) Encode in the format of x + d + string, where x is string.size(), d is a delimiter such as "#"
 * 2) Decode by updating a pointer/iterator within the input string, converting a segment of the input into an integer
 *    when a "#" is encountered, using that integer to determine where to extract the string, then updating the pointer
*/
class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        stringstream ss;
        int len = strs.size();
        for (int i = 0; i < len; i++) {
            ss << strs[i].size() << "#" << strs[i];
        }

        return ss.str();
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> res;

        string::iterator it = str.begin();
        while (it != str.end()) {
            string::iterator j = it;
            while (*j != '#') {
                ++j;
            }
            int length = stoi(string(it, j));
            res.push_back(string(j+1, j+1+length));
            it = j + 1 + length;
        }

        return res;

    }
};

/**
 * Execution of main to simulate testing (although only 2 "test cases" are used)
*/
int main() {
    Solution solution;

    cout << "\nTest 1: Input: [\"lint\",\"code\",\"love\",\"you\",\"###\"]\n" << endl;

    vector<string> strs{"lint","code","love","you","###"};
    string encodedStr = solution.encode(strs);
    cout << encodedStr << endl;

    vector<string> decodedStr = solution.decode(encodedStr);
    for (int i = 0; i < decodedStr.size(); i++) {
        cout << decodedStr[i] << endl;
    }

    cout << "\nTest 2: Input: [\"we\",\"say\",\":\",\"yes\",\"!!!\"]\n" << endl;

    vector<string> strs2{"we","say",":","yes","!!!"};
    string encodedStr2 = solution.encode(strs2);
    cout << encodedStr2 << endl;

    vector<string> decodedStr2 = solution.decode(encodedStr2);
    for (int i = 0; i < decodedStr2.size(); i++) {
        cout << decodedStr2[i] << endl;
    }

    return 0;
}