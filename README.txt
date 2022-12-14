基于哈夫曼编码的文档压缩器

Notes:
我（丁利）所做的工作：
1. 编写构建哈夫曼树所需的基础的数据结构的相关类
2. 整合其他组员分别编写的各部分代码。
3. 编写主函数，结合各函数接口。
4. 将所有代码整合后进行代码调试，发现并修正代码错误。

一些有价值的问题：
1. 调试过程中发现，若在同一次进程中多次调用基础功能里char_code函数为
不同文件中的字符进行编码，则在写入文件时总是在文件文件末尾写入而不会截断
后从头重新写入文件，造成错误。解决办法：在函数外定义一个全局整形变量
write_count用于记录写入文件的次数，若为第一次写入则截断上次写入后从头再次
写入；若不为第一次写入则从上次写入处续写（因为核心函数HuffmanCode函数为
递归逐句写入编码结果，故如此设计）。同时，再定义一个全局整型变量stack_count
初始化为1用于记录压入栈中的函数个数，若值为零，则说明一次编码操作完毕，
将write_count值重置为零，stack_count值置为1。

2. 字符编码功能在调试功能多次调用时中随机出现错误，表现为部分字符编码结果为null。
解决办法：发现出错原因是存储码字的数组下标变量count为全局变量，而在每次调用未将
count置0。因此我利用上个问题解决办法的stack_count变量，栈中函数个数为零说明
一次操作结束，此时将count置0。


3. 对f1.txt和f2.txt编码时都未出现问题，但在对f3.txt编码时出现编码异常，表现为部分字符
编码结果为null。解决办法：发现出错原因是存储编码结果的数组长度太短，将初始长度设置为
100即可
