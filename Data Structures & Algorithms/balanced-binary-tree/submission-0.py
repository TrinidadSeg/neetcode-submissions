# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def height(root):
            if not root: return [0, True]
            l, lbal = height(root.left)
            r, rbal = height(root.right)
            b = (abs(l-r) <= 1 and lbal and rbal)
            return [max(l, r)+1, b]
        h, b = height(root)
        return b;
        