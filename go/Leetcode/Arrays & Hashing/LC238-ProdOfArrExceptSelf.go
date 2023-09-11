package leetcode

func productExceptSelf(nums []int) []int {
	// Convenience variable
	n := len(nums)

	// Initialize arrays to store products to the L or R of index i
	leftProds := make([]int, n)
	rightProds := make([]int, n)

	// Starting values to allow for multiplication by 1 at the edges of array
	leftProds[0] = 1
	rightProds[n-1] = 1

	var j int
	// First Pass: Use Two Pointers to populate left/rightProds (besides starting vals)
	for i := n - 2; i >= 0; i-- {
		j = n - i - 1
		rightProds[i] = rightProds[i+1] * nums[i+1]
		leftProds[j] = leftProds[j-1] * nums[j-1]
	}

	// Second Pass: Replace values of nums array with our result
	for i := range nums {
		nums[i] = leftProds[i] * rightProds[i]
	}

	return nums
}
