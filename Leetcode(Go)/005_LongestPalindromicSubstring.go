package Leetcode

import "strings"

func longestPalindrome(s string) string {
	starstr, ans := "#", ""
	maxlength := 0
	for _, r := range s {
		starstr += string(r) + "#"
	}
	for i := 1; i < len(starstr)-1; i++ {
		cnt := 1
		for i-cnt >= 0 && i+cnt < len(starstr) && starstr[i-cnt] == starstr[i+cnt] {
			cnt++
		}
		cnt--
		if cnt > maxlength {
			maxlength = cnt
			ans = strings.Replace(starstr[i-cnt:i+cnt], "#", "", -1)
		}
	}
	return ans
}
