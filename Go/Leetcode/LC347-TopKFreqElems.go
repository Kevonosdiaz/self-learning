package leetcode

func topKFrequent(nums []int, k int) []int {
	seen := map[int]int{}
	ans := []int{}
	for i := range nums {
		seen[nums[i]]++
	}
	buckets := make([][]int, len(nums)+1)
	for k, v := range seen {
		buckets[v] = append(buckets[v], k)
	}
	for i := len(buckets) - 1; i >= 0 && len(ans) < k; i-- {
		for _, num := range buckets[i] {
			ans = append(ans, num)
			if len(ans) == k {
				break
			}
		}
	}

	return ans
}
