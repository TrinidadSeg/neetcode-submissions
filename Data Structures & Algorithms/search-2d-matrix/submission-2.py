class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l = 0
        cols = len(matrix[0])
        r = len(matrix) * cols - 1
        while (l <= r):
            mid = l + (r-l)//2
            mn = matrix[mid//cols][mid%cols]
            if (mn == target): return True
            elif (mn < target): l = mid + 1
            else: r = mid - 1
        return False