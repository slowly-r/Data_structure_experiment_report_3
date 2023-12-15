#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include "Huffman.h"

using namespace std;
unsigned int a, b;
int m;

//inline void operator delete(void* ptr) { };

void Select(HuffmanTree HT, int m, int* s1, int* s2)		//在一组数据中选出两个最小的数
{	//从这m个数里边选择最小的2个//把第一个进行标记就ok 
	int i;//从下标为1的位置开始计数 
	//int min=HT[1].weight;这里直接赋值不合理，假如第一次那个1就是最小被选选中，那么第2次还是被选中 
	int min1 = 1000;
	int min2 = 1000;//规定一个特别大的数 

	for (i = 1; i <= m; i++)
	{
		if (HT[i].parent == 0 && min1 > HT[i].weight)
		{
			min1 = HT[i].weight;
			*s1 = i;
		}
	}
	for (i = 1; i <= m; i++)
	{
		if (i != (*s1) && HT[i].parent == 0)
			if (HT[i].weight < min2)
			{
				min2 = HT[i].weight;
				*s2 = i;
			}
	}
}

void CreateHuffmanTree(HuffmanTree &HT, int n)
{
    int s1, s2, i;
    if (n <= 1) return;
    m = 2 * n - 1; 
    HT = new HTNode[m + 1];		//0号单元未用，所有需要动态分配m+1个单元，HT[m]表示根结点
    for (i = 1; i <= m; ++i)	//将1~m号单元中的双亲、左孩子、右孩子的下标都初始化为0
    {
        HT[i].parent = 0; HT[i].lchild = 0; HT[i].rchild = 0;
    }
	
//	std::string input;
//	std::getline(std::cin, input);

//	std::istringstream iss(input);
//	int count = 0;
//	while (count < n && iss >> HT[i].zifu >> HT[i].weight) {
//		++count;
	cout << "请输入字符与对应的权值：\n";

    for (i = 1; i <= n; ++i)		//输入各个结点名称与叶子结点的权值
    {
//		scanf("%c=%d", &HT[i].zifu, &HT[i].weight);
		cin >> HT[i].zifu;
		cout << " = ";
		cin >> HT[i].weight;
	}

    for (i = n + 1; i <= m; ++i)	//通过n-1次的选择、删除、合并来创建哈夫曼树
    {
        Select(HT, i - 1, &s1, &s2);
        HT[s1].parent = i;			//得到新结点i，从森林中删除s1,s2,将s1和s2的双亲域由0改为i
        HT[s2].parent = i;			
        HT[i].lchild = s1;			//s1，s2分别作为i的左右孩子
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;	//i的权值为左右孩子的权值之和
    }
}

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n)
{
	//从叶子到根逆向求每个字符的赫夫曼编码，存储在编码表HC中
	int i, start, c, f;
	HC = new char* [n + 1];						// 分配n个字符编码的头指针矢量
	char* cd = (char*)malloc(sizeof(char) * n);	// 分配临时存放编码的动态数组空间
	cd[n - 1] = '\0';							// 编码结束符

	for (i = 1; i <= n; ++i)
	{								// 逐个字符求赫夫曼编码
		start = n - 1;				// start开始时指向最后，即编码结束符位置
		c = i;
		f = HT[i].parent;			// f指向结点c的双亲结点
		while (f != 0)
		{							// 从叶子结点开始向上回溯，直到根结点
			--start;				// 回溯一次start向前指一个位置
			if (HT[f].lchild == c)
				cd[start] = '0';	// 结点c是f的左孩子，则生成代码0
			else
				cd[start] = '1';	// 结点c是f的右孩子，则生成代码1
			c = f;
			f = HT[f].parent;		// 继续向上回溯
		}
		// 求出第i个字符的编码      
		HC[i] = new char[n - start];// 为第i 个字符编码分配空间
		strcpy(HC[i], &cd[start]);	// 将求得的编码从临时空间cd复制到HC的当前行中
	}

	delete cd;						// 释放临时空间                           			
}
