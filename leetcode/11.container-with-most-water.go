package main

/*
 * @lc app=leetcode id=11 lang=golang
 *
 * [11] Container With Most Water
 */

// @lc code=start
func maxArea(height []int) int {
	i, j := 0, len(height)-1
	ans := 0
	for i != j {
		ans = max(min(height[i], height[j])*(j-i), ans)
		if height[i] < height[j] {
			i++
		} else {
			j--
		}
	}
	return ans
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

// @lc code=end
