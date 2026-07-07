/**
class Solution {
public:
    int findCatalan(int n) {

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        if (n >= 1)
            dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};
 */

 /**
  Recurrence

The nth Catalan number is

C
n
	​

=
i=0
∑
n−1
	​

C
i
	​

×C
n−i−1
	​


Reason:

Assume one pair of parentheses encloses i pairs inside it.

Then

Inside can be arranged in C(i) ways.
Remaining n-i-1 pairs can be arranged in C(n-i-1) ways.

Multiply them and sum over all possibilities.
  */