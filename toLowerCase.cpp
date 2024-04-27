#include <string>
#include <cctype>

class Solution {
public:
    string toLowerCase(string s) {
        for (char& c : s) {
            if (std::isupper(c)) {
                c = std::tolower(c);
            }
        }
        return s;
    }
};
