package main

import "sort"

/*
 * @lc app=leetcode id=15 lang=golang
 *
 * [15] 3Sum
 */

// @lc code=start
func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	ans := make([][]int, 0)
	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		all_two_sums := twoSum(nums[i+1:], -nums[i])
		for _, two_sums_idx := range all_two_sums {
			ans = append(ans, []int{nums[i], two_sums_idx[0], two_sums_idx[1]})
		}
	}
	return ans
}

func twoSum(nums []int, target int) [][]int {
	ans := make([][]int, 0)
	j := len(nums) - 1
	for i := 0; i < len(nums); i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for i < j && nums[i]+nums[j] > target {
			j--
		}
		if i < j && nums[i]+nums[j] == target {
			ans = append(ans, []int{nums[i], nums[j]})
		}
	}
	return ans
}

// @lc code=end
