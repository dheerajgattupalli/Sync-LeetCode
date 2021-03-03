class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        sum_ = 0
        for num in nums:
            sum_+=num
        n = len(nums)
        return int((n*(n+1)/2)) - sum_
        