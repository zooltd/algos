package main

/*
 * @lc app=leetcode id=1109 lang=golang
 *
 * [1109] Corporate Flight Bookings
 */

// @lc code=start
func corpFlightBookings(bookings [][]int, n int) []int {
	delta := make([]int, n+2)
	for _, booking := range bookings {
		fir := booking[0]
		last := booking[1]
		seats := booking[2]
		delta[fir] += seats
		delta[last+1] -= seats
	}
	a := make([]int, n+1)
	for i := 1; i <= n; i++ {
		a[i] = a[i-1] + delta[i]
	}
	for i := 1; i <= n; i++ {
		a[i-1] = a[i]
	}
	return a[:len(a)-1]
}

// @lc code=end
