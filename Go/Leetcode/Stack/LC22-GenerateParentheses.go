package leetcode

func generateParenthesis(n int) []string {
	var ans []string
	solve(n, n, "", &ans)
	return ans
}

// Helper function keeping track of recusion tree so far, appending parentheses based on case
func solve(l int, r int, curr string, ans *[]string) {
	if l == 0 && r == 0 {
		*ans = append(*ans, curr)
		return
	}

	if l == r || r == 0 {
		solve(l-1, r, curr+"(", ans)
	} else if l == 0 {
		solve(l, r-1, curr+")", ans)
	} else {
		// Try both remaining options
		solve(l-1, r, curr+"(", ans)
		solve(l, r-1, curr+")", ans)
	}
}
