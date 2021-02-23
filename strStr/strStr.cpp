class Solution {
public:
    int* buildNext(const string &P){
        int n = P.size(), j = 0;
        int *N = new int [n];
        int t = N[0] = -1;
        while(j < n - 1){
            if(t < 0 || P[t] == P[j]){
                ++t; ++j;
                N[j] = t;
            } else {
                t = N[t];
            }
        }
        return N;
    }
    int strStr(string haystack, string needle) {
        int m = haystack.size(), i = 0;
        int n = needle.size(), j = 0;
        if(n == 0 || haystack == needle){
            return 0;
        }
        int *next = buildNext(needle);
        while(j < n && i < m){
            if(j < 0 || haystack[i] == needle[j]){
                ++i; ++j;
            } else{
                j = next[j];
            }
        }
        delete [] next;
        return (j == n)? i - j : -1;
    }
};
