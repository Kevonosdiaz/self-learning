package leetcode

func twoSum(nums []int, target int) []int {
	seen := map[int]int{}
	var complement int
	res := []int{-1, -1}
	for i, num := range nums {
		complement = target - num
		_, val_exists := seen[complement]
		if val_exists {
			res[0] = i
			res[1] = seen[complement]
			return res
		} else {
			seen[num] = i
		}
	}

	return nil
}
