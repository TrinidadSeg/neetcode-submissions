class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def work(ans, num):
            nsub = []
            n = len(ans)
            for i in range(n):
                nsub.append(ans[i] + [num])
            return ans + nsub
        ans = [[]]
        for i in range(len(nums)):
            ans = work(ans, nums[i])
        return ans
        