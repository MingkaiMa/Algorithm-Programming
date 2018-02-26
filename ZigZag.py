from collections import defaultdict


class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        dic = defaultdict(list)

        row = 1
        forward_flag = 1

        for i in range(len(s)):
            if row == 1:
                dic[row].append(i)
                forward_flag = 1
                row += 1
                continue

            if row == numRows:
                dic[row].append(i)
                forward_flag = 0
                row -= 1
                continue

            if forward_flag == 1:
                dic[row].append(i)
                row += 1
                continue

            if forward_flag == 0:
                dic[row].append(i)
                row -= 1
                continue

        r = ''
        for i in dic:
            for j in dic[i]:
                r += s[j]

        return r

