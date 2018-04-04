package Leetcode

func lengthOfLongestSubstring(s string) int {
    start := 0
    maxLen := 0
    exist := make(map[int32]int) //为了搞定rune类型的字符，放入map中
    for end, c := range s {
        if k, ok := exist[c]; k >= start && ok {
            maxLen = max(maxLen, end - start)
            start = k + 1
        }
        exist[c] = end
    }
    maxLen = max(maxLen, len(s) - start)
    return maxLen
}

func max(a, b int) int {
    if a > b { 
        return a 
    }
    return b
}