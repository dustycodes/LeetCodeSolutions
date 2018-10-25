#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <assert.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1)
            return "";

        int l = 0, r = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            int len = max(len1, len2);
            if (len > r - l) {
                l = i - (len - 1) / 2;
                r = i + len / 2;
            }
        }

        return s.substr(l, r + 1 - l);
    }

    int expand(string s, int l, int r)
    {
        while (r < s.length() && l >= 0)
        {
            if (s[l] != s[r])
                break;

            --l;
            ++r;
        }
        return r - l - 1;
    }
};

void test_example(string s, vector<string> possible_answers)
{
    Solution solver;
    auto ans = solver.longestPalindrome(s);

    bool found = false;
    for (auto sol : possible_answers)
    {
        if (sol == ans)
        {
            found = true;
            break;
        }
    }
    std::cout << "Answer: " << ans << std::endl;

    assert(found == true);

    std::cout << "-> Passed" << std::endl;
}

int main(int argc, char** argv)
{
    // Example 1:
    test_example("babad", vector<string> {"bab", "aba"});

    // Example 2:
    test_example("cbbd", vector<string> {"bb"});

    test_example("ac", vector<string> {"a", "c"});

    // test_example("anugnxshgonmqydttcvmtsoaprxnhpmpovdolbidqiyqubirkvhwppcdyeouvgedccipsvnobrccbndzjdbgxkzdbcjsjjovnhpnbkurxqfupiprpbiwqdnwaqvjbqoaqzkqgdxkfczdkznqxvupdmnyiidqpnbvgjraszbvvztpapxmomnghfaywkzlrupvjpcvascgvstqmvuveiiixjmdofdwyvhgkydrnfuojhzulhobyhtsxmcovwmamjwljioevhafdlpjpmqstguqhrhvsdvinphejfbdvrvabthpyyphyqharjvzriosrdnwmaxtgriivdqlmugtagvsoylqfwhjpmjxcysfujdvcqovxabjdbvyvembfpahvyoybdhweikcgnzrdqlzusgoobysfmlzifwjzlazuepimhbgkrfimmemhayxeqxynewcnynmgyjcwrpqnayvxoebgyjusppfpsfeonfwnbsdonucaipoafavmlrrlplnnbsaghbawooabsjndqnvruuwvllpvvhuepmqtprgktnwxmflmmbifbbsfthbeafseqrgwnwjxkkcqgbucwusjdipxuekanzwimuizqynaxrvicyzjhulqjshtsqswehnozehmbsdmacciflcgsrlyhjukpvosptmsjfteoimtewkrivdllqiotvtrubgkfcacvgqzxjmhmmqlikrtfrurltgtcreafcgisjpvasiwmhcofqkcteudgjoqqmtucnwcocsoiqtfuoazxdayricnmwcg", )

    Solution s;
    string f = s.longestPalindrome("anugnxshgonmqydttcvmtsoaprxnhpmpovdolbidqiyqubirkvhwppcdyeouvgedccipsvnobrccbndzjdbgxkzdbcjsjjovnhpnbkurxqfupiprpbiwqdnwaqvjbqoaqzkqgdxkfczdkznqxvupdmnyiidqpnbvgjraszbvvztpapxmomnghfaywkzlrupvjpcvascgvstqmvuveiiixjmdofdwyvhgkydrnfuojhzulhobyhtsxmcovwmamjwljioevhafdlpjpmqstguqhrhvsdvinphejfbdvrvabthpyyphyqharjvzriosrdnwmaxtgriivdqlmugtagvsoylqfwhjpmjxcysfujdvcqovxabjdbvyvembfpahvyoybdhweikcgnzrdqlzusgoobysfmlzifwjzlazuepimhbgkrfimmemhayxeqxynewcnynmgyjcwrpqnayvxoebgyjusppfpsfeonfwnbsdonucaipoafavmlrrlplnnbsaghbawooabsjndqnvruuwvllpvvhuepmqtprgktnwxmflmmbifbbsfthbeafseqrgwnwjxkkcqgbucwusjdipxuekanzwimuizqynaxrvicyzjhulqjshtsqswehnozehmbsdmacciflcgsrlyhjukpvosptmsjfteoimtewkrivdllqiotvtrubgkfcacvgqzxjmhmmqlikrtfrurltgtcreafcgisjpvasiwmhcofqkcteudgjoqqmtucnwcocsoiqtfuoazxdayricnmwcg");

    std::cout << f << std::endl;

    return 0;
}
