# 150. Evaluate Reverse Polish Notation

##### tags: `Queue`
<br>

[LeetCode](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0150.%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC.md)

根據 逆波蘭表示法 (Reverse Polish Notation)，求表達式的值。

有效的運算子包含 `+`,`-`,`*`,`/`。每個運算子可以是整數，也可以是另一個逆波蘭表達事。


**範例 1**
```
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
```

**範例 2**
```
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
```

**範例 1**
```
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```


**邊界限制**
- 1 <= tokens.length <= 10<sup>4</sup>
- `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200]`.


## 思路

![150.逆波兰表达式求值](https://code-thinking.cdn.bcebos.com/gifs/150.逆波兰表达式求值.gif)

### 此題解法
```cpp

```

PHP
```PHP
class Solution {
    /**
     * @param String[] $tokens
     * @return Integer
     */
    function evalRPN($tokens) {
        $stack = [];
        foreach ($tokens as $token) {
            if (
                $token === '+' || $token === '-'
                || $token === '*' || $token === '/'
            ) {
                $second = (int)array_pop($stack);
                $first = (int)array_pop($stack);
                $stack[] = match ($token) {
                    '+' => $first + $second,
                    '-' => $first - $second,
                    '*' => $first * $second,
                    '/' => $first / $second,
                };
            } else {
                $stack[] = $token;
            }
        }
        return (int)$stack[0];
    }
}
```