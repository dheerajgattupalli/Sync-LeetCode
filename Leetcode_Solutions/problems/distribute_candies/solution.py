class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        set_candyType = set(candyType)
        return min(len(candyType)//2,len(set_candyType))
        