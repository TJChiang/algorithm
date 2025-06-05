
class ClimbingStairs:
    def solve_iterative(self, n: int) -> int:
        if n < 1 or n > 45:
            return 0

        if n == 1 or n == 2:
            return n

        beforePrev = 1
        prev = 2

        for i in range(3, n + 1):
            curr = beforePrev + prev
            beforePrev = prev
            prev = curr

        return prev

    def solve_recursive(self, n: int) -> int:
        if n < 1 or n > 45:
            return 0

        if n == 1 or n == 2:
            return n

        return self.solve_recursive(n - 1) + self.solve_recursive(n - 2)
