package main

/*
 * @lc app=leetcode id=283 lang=golang
 *
 * [283] Move Zeroes
 */

// @lc code=start
func moveZeroes(nums []int) {
	curr := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != 0 {
			nums[curr] = nums[i]
			curr++
		}
	}
	for ; curr < len(nums); curr++ {
		nums[curr] = 0
	}
}

// @lc code=end
