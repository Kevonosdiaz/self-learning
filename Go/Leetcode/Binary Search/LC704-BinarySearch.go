package leetcode

func search(nums []int, target int) int {
	l, r := 0, len(nums)-1

	for l <= r {
		m := (l + r) / 2 // Alternatively we can do (r - l)/2 + l in order to avoid integer overflow
		if nums[m] > target {
			r = m - 1
		} else if nums[m] < target {
			l = m + 1
		} else {
			return m
		}
	}

	return -1
}
