package main

import "fmt"

func main() {
	nums := []int{}
	for i := 0; i <= 10; i++ {
		nums = append(nums, i)
		if nums[i] % 2 == 0 {
			fmt.Println(nums[i], " is even")
		} else {
			fmt.Println(nums[i], " is odd")
		}
	}
}