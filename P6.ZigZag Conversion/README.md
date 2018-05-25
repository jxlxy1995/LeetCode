## C++

简单的字符串处理，假设一个V字形的字符串为一组，那么这一组就会有loopN = numRows * 2 - 2多个字符。前numRows个就是按顺序放置，超过numRows的位置为numRows - (2 + j - numRows)。处理完后有numRows个字符串，按顺序拼接起来即可。