from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class ValidateBinarySearchTree:
    # Time complexity: O(n)
    # Space complexity: O(n)
    def isValidBST_dfs(self, root: Optional[TreeNode]) -> bool:

        def dfs(node: Optional[TreeNode], left: float, right: float) -> bool:
            if not node:
                return True

            if node.val <= left or node.val >= right:
                return False

            return dfs(node.left, left, node.val) and dfs(node.right, node.val, right)

        return dfs(root, float('-inf'), float('inf'))
