# chapter11

## 思考题
###Problems 1
#### Q 散列最长探查的界
A hash table of size m is used to store n items, with n ≤ m/2. Open addressing is used for collision resolution.

a.Assuming uniform hashing, show that for i=1,2,…,n, the probability is at most 2^−k that the ith insertion requires strictly more than k probes.

b.Show that for i=1,2,…,n, the probability is O(1/n^2) that the ith insertion requires more than 2lgn probes.

Let the random variable Xi denote the number of probes required by the ith insertion. You have shown in part (b) that  . Let the random variable   denote the maximum number of probes required by any of the n insertions.

c.Show that Pr{X > 2lgn}=O(1/n).

d.Show that the expected length E[X] of the longest probe sequence is O(lgn).