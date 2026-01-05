import java.util.ArrayList;
import java.util.List;

/**
 * Union-Find (Disjoint Set Union) algorithm.
 * <p>
 * - <a href=
 * "https://leetcode.com/problems/lexicographically-smallest-equivalent-string">1061.
 * Lexicographically Smallest Equivalent String</a>
 */
public class UnionFind {

    // The parent node of i-th element.
    private final List<Integer> parent;

    public UnionFind(int size) {
        parent = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            parent.add(i);
        }
    }

    public int find(int x) {
        if (parent.get(x) != x) {
            parent.set(x, find(parent.get(x))); // Optimize: Path compression
        }
        return parent.get(x);
    }

    public void union(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        if (parentX == parentY)
            return; // Already in the same set
        if (parentX > parentY) {
            parent.set(parentX, parentY); // Optimize: Union by rank => always attach larger to smaller
        } else {
            parent.set(parentY, parentX);
        }
    }
}
