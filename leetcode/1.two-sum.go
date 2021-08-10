package main

/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 */

// @lc code=start
func twoSum(nums []int, target int) []int {
	hashTable := map[int]int{}
	for i, v := range nums {
		if p, ok := hashTable[target-v]; ok {
			return []int{p, i}
		}
		hashTable[v] = i
	}
	return nil
}

// @lc code=end
