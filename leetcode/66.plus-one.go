package main

/*
 * @lc app=leetcode id=66 lang=golang
 *
 * [66] Plus One
 */

// @lc code=start
func plusOne(digits []int) []int {
	index := len(digits) - 1
	if index < 0 {
		return digits
	}
	for ; index >= 0; index-- {
		if digits[index] != 9 {
			break
		} else {
			digits[index] = 0
		}
	}
	if index < 0 {
		digits = append([]int{1}, digits...)
	} else {
		digits[index] = digits[index] + 1
	}
	return digits
}

// @lc code=end
