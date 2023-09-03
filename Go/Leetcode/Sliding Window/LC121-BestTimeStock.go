package leetcode

func maxProfit(prices []int) int {
	maxProfit := 0
	l := 0
	r := 1
	n := len(prices)

	var profit int

	for r < n {
		if prices[l] < prices[r] {
			profit = prices[r] - prices[l]
			if profit > maxProfit {
				maxProfit = profit
			}
		} else {
			l = r
		}
		r++
	}

	return maxProfit
}
