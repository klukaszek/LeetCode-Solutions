class Solution:
    def customSortString(self, order: str, s: str) -> str:
        
        #create dictionary of character occurences 
        d = {}
        
        for char in s:
            if char not in d:
                d[char] = 1
            else:
                d[char] += 1
                
        my_str = ''
        
        #build string using order by getting character from dictionary using order string
        for char in order:
            for i in range (d.get(char, 0)):
                my_str += char
            
            d[char] = 0
        
        #add remaining characters that were not in the order string to return string
        for i in range(26):
            for j in range(d.get(chr(i+97),0)):
                my_str += chr(i+97)
                
        return my_str
      
      
"""
#C++ solution

class Solution {
public:
    string customSortString(string order, string s) {
        sort(s.begin(), s.end(), [&](char a, char b){return order.find(a) < order.find(b);});
        return s;
    }
};

Note: C++ solution using sort() with lambda expression is much more efficient but I don't believe that it is an intuitive solution so I chose to focus on the python one.
10/17/2022 20:40	Accepted	9 ms	6.1 MB	cpp
"""
