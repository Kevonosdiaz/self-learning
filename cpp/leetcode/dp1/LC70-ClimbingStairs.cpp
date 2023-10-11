// LC70 - Climbing Stairs

class Solution {
    public:
    int climbStairsR(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        return climbStairsR(n-1) + climbStairsR(n-2); 
    }

    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int arr[n];

        arr[0] = 1;
        arr[1] = 2;

        for (int i = 2; i < n; i++) {
            arr[i] = arr[i-1] + arr[i-2];
        }

        return arr[n-1];
    }
};
