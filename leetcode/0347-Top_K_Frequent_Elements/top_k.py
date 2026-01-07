import heapq
from typing import List


class TopK:
    # Time Complexity: O(n + m log m) where n is the length of nums and m is the number of unique elements in nums
    # worst case O(n log n) when all elements are unique, m = n
    # Space Complexity: O(m + k) where m is the number of unique elements in nums and k is the length of the output list
    # worst case O(n) when all elements are unique, k = m = n
    def solve_origin(self, nums: List[int], k: int) -> List[int]:
        freq_map = {}

        for num in nums:
            if num not in freq_map:
                freq_map[num] = 0
            else:
                freq_map[num] += 1

        freq_map = sorted(freq_map.items(), key=lambda x: x[1], reverse=True)

        ans = [1] * k
        freq = list(dict(freq_map).keys())
        for i in range(0, k):
            ans[i] = freq[i]

        return ans

    # Time Complexity: O(n log k) where n is the length of nums
    # Space Complexity: O(n)
    def solve_by_max_heap(self, nums: List[int], k: int) -> List[int]:
        max_heap = []
        counter = {}

        # Build frequency map
        for n in nums:
            counter[n] = 1 + counter.get(n, 0)

        # Build max heap
        for num, count in counter.items():
            # python has only min heap (heapq), so we use negative count to simulate max heap
            # Push negative count to simulate max heap
            heapq.heappush(max_heap, (-count, num))

        res = []

        # Extract top k elements
        while len(res) < k:
            count, num = heapq.heappop(max_heap)
            res.append(num)

        return res

    # Time Complexity: O(n) where n is the length of nums
    # Space Complexity: O(n)
    def solve_by_bucket_sort(self, nums: List[int], k: int) -> List[int]:
        if not nums:
            return []

        # Step 1: Build frequency map
        freq_map = {}
        for num in nums:
            freq_map[num] = freq_map.get(num, 0) + 1

        # Step 2: Build buckets
        # The maximum frequency any number can have is len(nums)
        max_freq = max(freq_map.values())
        # Create buckets where index represents frequency
        buckets = [[] for _ in range(max_freq + 1)]
        # Fill the buckets
        for num, freq in freq_map.items():
            buckets[freq].append(num)

        # Step 3: Gather top k frequent elements
        res = []
        # Iterate from highest frequency to lowest
        for freq in range(max_freq, 0, -1):
            # Check if there are numbers with this frequency
            for num in buckets[freq]:
                # Add number to result
                res.append(num)
                if len(res) == k:
                    return res

        return res
