
### 题目介绍

将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
```
P   A   H   N
A P L S I I G
Y   I   R
```
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"

### 示例1

``` 
输入：s = "PAYPALISHIRING", numRows = 3 
输出："PAHNAPLSIIGYIR"
```

### 答案

#### 官方思路

通过从左向右迭代字符串，我们可以轻松地确定字符位于 Z 字形图案中的哪一行。

#### 算法

我们可以使用 \text{min}( \text{numRows}, \text{len}(s))min(numRows,len(s)) 个列表来表示 Z 字形图案中的非空行。

从左到右迭代 ss，将每个字符添加到合适的行。可以使用当前行和当前方向这两个变量对合适的行进行跟踪。

只有当我们向上移动到最上面的行或向下移动到最下面的行时，当前方向才会发生改变。

```
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};
```

#### 个人解法
```
class Solution {
public:
    string convert(string s, int numRows) {
        int s_length = s.size();

        string convertString = "";
        if (numRows <= 0) {
            convertString;
        }

        if (numRows == 1) {
            return s;
        }

        int row = 0;
        int column = 0;
        int index = 0;
        vector<vector<char>> array_convert;
        while (index < s_length) {
            array_convert.push_back(vector<char>(numRows));
            while (column < numRows) {
                if (index < s_length) {
                    char ch = s.at(index);
                    array_convert.at(row).at(column) = ch;
                    index++;
                    column++;
                }
                else {
                    break;
                }
            }
            column--;
            while (column >= 1) {
                if (index < s_length) {
                    column--;
                    row++;
                    array_convert.push_back(vector<char>(numRows));
                    char ch = s.at(index);
                    array_convert.at(row).at(column) = ch;
                    index++;
                }
                else {
                    break;
                }   
            }
            column++;
        }
        
        int row_array = array_convert.size();
        for (column = 0; column < numRows; column++) {

            for (row = 0; row < row_array; row++) {
                if (array_convert.at(row).at(column) == ',' || array_convert.at(row).at(column) == '.' ||
                    (array_convert.at(row).at(column) >= 'A' && array_convert.at(row).at(column) <= 'Z') ||
                    ((array_convert.at(row).at(column) >= 'a' && array_convert.at(row).at(column) <= 'z'))) {
                    convertString.push_back(array_convert.at(row).at(column));
                }
            }
        }

        return convertString;
    }
};
int main()
{
    Solution s;
    cout << s.convert("PAYPALISHIRING",3) << endl;
}
```
