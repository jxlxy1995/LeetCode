## C++

第一种方法和前面一题的解法类似，拆分字符串然后哈希  

后一种是网站上优化的方法，倒序遍历字符串并且判断当前字符所代表值是否小于上一个，如IV，遍历到I时比V小则记录-I即-1，最后计算总之5+(-1) = 4。以此类推