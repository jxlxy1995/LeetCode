## C++

本题相对来说是比较简单的链表问题，但存在一个进阶问题就是如何只遍历一遍完成。代码中含有三种解法。  
解法一是需遍历两遍的解法，我这边做法是倒置移除节点再倒置，因为刚好复习下单链表倒置的写法。还有一种写法就是第一次遍历获得链表长度L，倒数第n个节点就是正数L−n+1个，然后进行删除；  
解法二解法三都是一个思路，第二种写法是我自己写的相对繁复一些，解法三更为巧妙。思路是使用两个指针而不是一个指针。第一个指针从列表的开头向前移动 n+1n+1 步，而第二个指针将从列表的开头出发。现在，这两个指针被 nn 个结点分开。我们通过同时移动两个指针向前来保持这个恒定的间隔，直到第一个指针到达最后一个结点。此时第二个指针将指向从最后一个结点数起的第 nn 个结点。我们重新链接第二个指针所引用的结点的 next 指针指向该结点的下下个结点。（来自LeetCode标解https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-by-l/）