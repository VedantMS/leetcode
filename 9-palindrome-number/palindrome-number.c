bool isPalindrome(int x) {
    int len = 0;
    int num = x;
    long ans = 0;
    while(num > 0) {
        ans *= 10;
        ans += num % 10;
        num /= 10;
    }
    return x == ans;
}