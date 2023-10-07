Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters.
The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words.
The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"




#include "bits/stdc++.h"
using namespace std;
{
	class Solution {
public:
    string reverseWords(string s) {

        int n=s.length();
        string ans="";
        int i=0;
        while(i<n)
        {
            string temp="";
            while(s[i]==' ' and i<n)
            {
                i++;
            }
            while(s[i]!=' ' and i<n)
            {
                temp+=s[i];
                i++;
            }

            if(temp.size()>0)
            {
                if(ans.size()==0)
                {
                    ans+=temp;
                }
                else {
                    ans=temp+" "+ans;
                }
            }


        }
        return ans;

    }
};
}

