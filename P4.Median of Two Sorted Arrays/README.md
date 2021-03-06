## C++:

最简单想法就是说对这两个数组每一位进行比较排序，排到（m+n）/2时结束，然后那这一个或者两个值即可，但这样的时间复杂度为O(m+n)，题目要求的是logn级别的复杂度，故还需优化；

## C:
那么所谓求两个数组的中位数，就是求第（m+n）/2大的一个值，即传化成了求第k大值的一个问题。那么我们先不考虑一些边界条件，假设这两个数组分别为a,b，并且他们的大小都大于k/2，那么我们去比较a[k/2-1]和b[k/2-1]的大小，那么出现以下三种情况：

如果a[k/2-1]<b[k/2-1]，这表示a[0]到a[k/2-1]的元素都在a和b合并之后的前k小的元素中。换句话说，a[k/2-1]不可能大于两数组合并之后的第k小值，所以我们可以将其抛弃；

那么当a[k/2-1]>b[k/2-1]可以得出类似的推论，并做相应的操作；

那么最后结果是，要么当a[k/2-1]=b[k/2-1]时，我们已经找到了第k小的数，也即这个相等的元素，我们将其记为m。由于在a和b中分别有k/2-1个元素小于m，所以m即是第k小的数；要么某一个数组已被耗尽，那么就转化成了求剩下的数组的第kk（经过多次舍弃后的k）小的值了
