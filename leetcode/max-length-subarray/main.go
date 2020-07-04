package main

import "fmt"

//	Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
//
//	Example 1:
//
//	Input:
//	A: [1,2,3,2,1]
//	B: [3,2,1,4,7]
//	Output: 3
//	Explanation:
//	The repeated subarray with maximum length is [3, 2, 1].
//
//
//	Note:
//
//	1 <= len(A), len(B) <= 1000
//	0 <= A[i], B[i] < 100

func main() {
	fmt.Println(findLength([]int{0, 1, 1, 1, 1}, []int{1, 0, 1, 0, 1}))
}

func findLength(A []int, B []int) int {
	dp := make([][]int, len(A)+1)
	for i := 0; i <= len(A); i++ {
		dp[i] = make([]int, len(B)+1)
	}
	result := 0
	for i := 1; i <= len(A); i++ {
		for j := 1; j <= len(B); j++ {
			if A[i-1] == B[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
				result = max(result, dp[i][j])
			}
		}
	}
	return result
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
