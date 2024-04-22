/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.



Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int i, n = num.size();
        stack<char> s;
        string res;

        for (i = 0; i < n; ++i)
        {
            while (!s.empty() && s.top() > num[i] && k > 0)
            {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }

        for (i = 0; i < k; ++i)
            s.pop();

        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }

        while (res.size() > 0 && res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        if (res.size() == 0)
            res.push_back('0');
        return res;
    }
#if 0
    string removeKdigits(string num, int k) {
        int i;
        
        if(num.size() == 0)
            return result;
        
        removeDigits(num, k, 0);
        
        /* remove leading 0s */
        i = 0;
        while(i < result.size() && result[i] == '0')
            i++;
        if(i == result.size())
            result = '0';
        else
            result = result.substr(i, result.size()-i);
        return result;
    }
private:
    /* remove k digits start from num[start] */
    void removeDigits(string &num, int k, int start)
    {
        int i, len = num.size() - start, smallest = INT_MAX, position;
        
        /* if we have reached the end, return */
        if(start == num.size())
            return;
        
        /* if k == 0, push in remaining string and return */
        if(k == 0)
        {
            result += num.substr(start, len);
            return;
        }
        
        /* if len == k, remove everything remained and return */
        if(len == k)
        {
            if(result.size() == 0)
                result += '0';
            return;
        }
        
        /* since we can remove at most k digits, we need to find smallest from first (k+1) digits and make it appear as first */
        for(i = start; i <= start+k; i++)
            if(num[i] - '0' < smallest)
            {
                smallest = num[i] - '0';
                position = i;
            }
        
        /* we essetially remove num[start...position-1] and include num[position] in the result */
        result += num[position];
        /* go into recursion from position+1 */
        removeDigits(num, k-(position-start), position+1);
    }
    
    string result;
#endif
};