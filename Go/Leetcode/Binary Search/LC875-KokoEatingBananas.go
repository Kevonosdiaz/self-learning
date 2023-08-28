package leetcode

import "math"

func minEatingSpeed(piles []int, h int) int {
	l := 1
	r := maxInSlice(piles)
	res := r

	for l <= r {
		mid := l + (r-l)/2
		hours := 0
		for _, v := range piles {
			hours += int(math.Ceil(float64(v) / float64(mid)))
		}

		if hours <= h {
			if mid < res {
				res = mid
			}
			r = mid - 1
		} else {
			l = mid + 1
		}
	}

	return res
}

func maxInSlice(sl []int) int {
	max := 0
	for _, v := range sl {
		if v > max {
			max = v
		}
	}

	return max
}
