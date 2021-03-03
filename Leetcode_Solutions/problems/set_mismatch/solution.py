class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        sum_ = 0
        sqr =0
        for num in nums:
            sqr+= num*num
            sum_+= num
        n = len(nums)
        act_sum = n*(n+1)/2
        act_sqr_sum = n*(n+1)*(2*n+1)/6
        diff_ab = act_sum - sum_
        diff_sqr_ab = act_sqr_sum - sqr
        sum_ab = diff_sqr_ab/diff_ab
        a = int((sum_ab + diff_ab)/2)
        b = int(sum_ab - a)
        return [b,a]
        