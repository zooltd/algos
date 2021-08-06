package main

/*
 * @lc app=leetcode id=1248 lang=golang
 *
 * [1248] Count Number of Nice Subarrays
 */
func numberOfSubarraysRaw(nums []int, k int) int {
	ans := 0
	nums = append([]int{0}, nums...)
	s := make([]int, len(nums))
	for i := 1; i < len(nums); i++ {
		s[i] = s[i-1] + nums[i]%2
	}
	// nums: [1,1,2,1,1] => [0,1,1,0,1,1]
	// s:  [0,1,2,2,3,4]

	for r := 1; r < len(s); r++ {
		for l := 1; l <= r; l++ {
			if s[r]-s[l-1] == k {
				ans++
			}
		}
	}
	return ans
}

// Optimize:
// 1. for each r∈[1,n), considering how many l∈[1,r] exists, let s[r] - s[l-1] == k
// 2. for each r∈[1,n), considering how many l∈[0,r) exists, let s[r] - s[l] == k
// 3. for each r∈[1,n), considering how many l∈[0,r) exists, let s[l] == k - s[r]

// @lc code=start
func numberOfSubarrays(nums []int, k int) int {
	ans := 0
	nums = append([]int{0}, nums...)
	s := make([]int, len(nums))
	for i := 1; i < len(nums); i++ {
		s[i] = s[i-1] + nums[i]%2
	}

	cnt := make([]int, len(s))
	for _, v := range s {
		cnt[v] += 1
	}
	for i := 1; i < len(nums); i++ {
		if s[i]-k >= 0 {
			ans += cnt[s[i]-k]
		}
	}
	return ans
}

// @lc code=end
