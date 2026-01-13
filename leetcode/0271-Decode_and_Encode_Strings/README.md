# 271. Decode and Encode Strings

###### tags: `array`

[LeetCode](https://leetcode.com/problems/encode-and-decode-strings/description/) (subscribe required)

[NeetCode](https://neetcode.io/problems/string-encode-and-decode/question)

Problem Context

Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:
```
string encode(vector<string> strs) {
    // ... your code
    return encoded_string;
}
```

Machine 2 (receiver) has the function:
```
vector<string> decode(string s) {
    //... your code
    return strs;
}
```

So Machine 1 does:
```
string encoded_string = encode(strs);
```

and Machine 2 does:
```
vector<string> strs2 = decode(encoded_string);
```

`strs2` in Machine 2 should be the same as `strs` in Machine 1.

Implement the encode and decode methods.

**範例 1**
```
Input: dummy_input = ["Hello","World"]

Output: ["Hello","World"]

Explanation:
Machine 1:
Codec encoder = new Codec();
String msg = encoder.encode(strs);
Machine 1 ---msg---> Machine 2

Machine 2:
Codec decoder = new Codec();
String[] strs = decoder.decode(msg);
```

**範例 2**
```
Input: dummy_input = [""]

Output: [""]
```

**限制邊界**
- 0 <= strs.length < 100
- 0 <= strs[i].length < 200
- `strs[i]` contains any possible characters out of `256` valid ASCII characters.

## 思路

### Solution

Let `strs` be encoded as `{length}#{string}` for each string in the list, where `length` is the length of the string and `#` is a delimiter. This way, we can easily decode the string by reading the length first and then extracting the corresponding substring.

e.g.
```
Input: strs = ["Hello","World"]
Encoded: "5#Hello5#World"
Decoded: ["Hello","World"]
```

- Time Complexity: O(N), where N is the total length of all strings in the input list.
- Space Complexity: O(M + N), where M is the length of the encoded string and N is the number of strings.
