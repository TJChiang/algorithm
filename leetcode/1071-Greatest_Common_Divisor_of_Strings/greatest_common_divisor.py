class BruteForceSolution:
    def isValid(self, str1: str, str2: str, k: int) -> bool:
        len1: int = len(str1)
        len2: int = len(str2)
        # 若兩個字串長度不是公因子 k 的倍數，則不可能有最大公因子
        if len1 % k > 0 or len2 % k > 0:
            return False

        # 取前 k 個字元作為公因子字串
        baseStr: str = str1[:k]
        # 分別取得長度 k 對於兩個字串長度的倍數
        div1: int = len1 // k
        div2: int = len2 // k
        # 公因子字串乘上倍數，應該與原始字串相等
        # 若兩個字串皆相等，則 baseStr 為最大公因子字串
        return str1 == baseStr * div1 and str2 == baseStr * div2

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        len1: int = len(str1)
        len2: int = len(str2)
        # 取兩個字串最小長度，才有可能找到最大公因子
        minLength: int = min(len1, len2)
        for i in range(minLength, 0, -1):
            if self.isValid(str1, str2, i):
                return str1[:i]
        return ""

class GreatestCommonDivisor:
    # 取得最大公因子字串長度
    def _gcd(self, len1: int, len2: int) -> int:
        while len2:
            len1, len2 = len2, len1 % len2
        return len1

    def _rgcd(self, len1: int, len2: int) -> int:
        if len2 == 0:
            return len1
        return self._rgcd(len2, len1 % len2)

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # 若兩字串有最大公因子字串，則兩字串相加，不論順序都應該相等
        if str1 + str2 != str2 + str1:
            return ""

        matchLength: int = self._gcd(len(str1), len(str2))
        return str1[:matchLength]
