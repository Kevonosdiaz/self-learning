package leetcode

func dailyTemperatures(temperatures []int) []int {
	res := make([]int, len(temperatures))
	st := []int{0}

	for i := 0; i < len(temperatures); i++ {
		for len(st) != 0 && temperatures[i] > temperatures[st[len(st)-1]] {
			res[st[len(st)-1]] = i - st[len(st)-1]
			st = st[:len(st)-1]
		}
		st = append(st, i)
	}

	return res
}
