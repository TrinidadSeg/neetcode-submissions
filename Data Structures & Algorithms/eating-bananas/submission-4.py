class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)
        while (l < r):
            mid = l + (r-l)//2
            works = self.iterate(piles, h, mid)
            if works: r = mid
            else: l = mid + 1

        return l

    def iterate(self, piles, h, t):
        c = 0
        for i in piles:
            c += math.ceil(i/t)
        return (c <= h)