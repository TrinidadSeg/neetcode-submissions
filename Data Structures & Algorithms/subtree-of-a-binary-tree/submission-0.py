# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def check(p, q):
            if not p and not q: return True
            if not p and q or p and not q or (p.val != q.val): return False
            else: return (check(p.left, q.left) and check(p.right, q.right))
        def explore(r, s):
            if not r: return False;
            b1 = False
            if (r.val == s.val): b1= check(r, s)
            b2 = explore(r.left, s)
            b3 = explore(r.right, s)
            return b1 or b2 or b3
        return explore(root, subRoot)