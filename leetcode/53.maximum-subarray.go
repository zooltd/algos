package main

import "math"

/*
 * @lc app=leetcode id=53 lang=golang
 *
 * [53] Maximum Subarray
 */

// @lc code=start
func maxSubArray(nums []int) int {
	s := make([]int, len(nums)+1)
	for i := 1; i < len(s); i++ {
		s[i] = s[i-1] + nums[i-1]
	}
	// nums = [|  -2, 1, -3, 4, -1, 2, 1, -5, 4]
	//    s = [0, -2, -1, -4, 0, -1, 1, 2, -3, 1]
	// [| -1]
	// [0 -1]
	max := math.MinInt32
	// for r := 1; r < len(s); r++ {
	// 	for l := 0; l < r; l++ {
	// 		if del := s[r] - s[l]; del > max {
	// 			max = del
	// 		}
	// 	}
	// }
	min_s_l := s[0]
	for r := 1; r < len(s); r++ {
		if del := s[r] - min_s_l; del > max {
			max = del
		}
		if s[r] < min_s_l {
			min_s_l = s[r]
		}
	}

	return max
}

// @lc code=end
