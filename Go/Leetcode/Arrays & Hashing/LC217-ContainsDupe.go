package leetcode

func containsDuplicate(nums []int) bool {
	mp := map[int]int{}
	for _, num := range nums {
		_, val_found := mp[num]
		if val_found {
			return true
		} else {
			mp[num]++
		}
	}

	return false
}
