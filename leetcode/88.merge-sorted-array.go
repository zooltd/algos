package main

/*
 * @lc app=leetcode id=88 lang=golang
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
func merge(nums1 []int, m int, nums2 []int, n int) {
	curr := m + n - 1
	m--
	n--
	for ; m >= 0 && n >= 0; curr-- {
		if nums1[m] <= nums2[n] {
			nums1[curr] = nums2[n]
			n--
		} else {
			nums1[curr] = nums1[m]
			m--
		}
	}
	for ; m >= 0; m-- {
		nums1[curr] = nums1[m]
		curr--
	}
	for ; n >= 0; n-- {
		nums1[curr] = nums2[n]
		curr--

	}
}

// @lc code=end
