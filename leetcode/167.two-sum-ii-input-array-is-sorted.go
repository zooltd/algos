package main

/*
 * @lc app=leetcode id=167 lang=golang
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
func twoSum(numbers []int, target int) []int {
	j := len(numbers) - 1
	for i := 0; i < len(numbers); i++ {
		for i < j && numbers[i]+numbers[j] > target {
			j--
		}
		if i < j && numbers[i]+numbers[j] == target {
			return []int{i + 1, j + 1}
		}
	}
	return []int{}
}

// @lc code=end
