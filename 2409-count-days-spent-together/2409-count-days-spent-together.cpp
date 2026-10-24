class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        return max(0, min(num(leaveAlice), num(leaveBob)) - max(num(arriveAlice), num(arriveBob)) + 1);
    }

    int num(string &s) {
        int a = (s[0] - '0') * 10 + (s[1] - '0');
        int b = (s[3] - '0') * 10 + (s[4] - '0');

        return (275 * a) / 9 - 30 - 2 * ((a + 9) / 12) + b;
    }
};