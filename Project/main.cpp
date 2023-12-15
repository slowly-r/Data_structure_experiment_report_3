#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <iomanip>
#include "Huffman.h"

using namespace std;
HuffmanTree HUF;
HuffmanCode HUF_CODE;

char yuanwen[8];

void show(HuffmanTree HT, HuffmanCode HC, int n)
{
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		cout << i << "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
	}

	for (int i = 1; i <= n; i++)
		cout << HT[i].zifu << "编码为" << HC[i] << endl;
	
}

void second_cin(HuffmanTree HT, HuffmanCode HC, int n)
{
	cout << "请输入原文内容：";
	cin >> yuanwen;
	cout << "压缩后编码：";
	for (int i = 0; i < 8; i++)
	{
		for (int y = 1; y <= n; y++)
		{
			if (yuanwen[i] == HT[y].zifu)
			{
				cout << HC[y];
			}
		}
	}

}

int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int n;
	cout << "请输入叶子结点的个数：";
	cin >> n;											//输入赫夫曼树的叶子结点个数
	CreateHuffmanTree(HT, n);
	CreatHuffmanCode(HT, HC, n);
	show(HT, HC,n);

	second_cin(HT, HC, n);

	system("pause");

	return 0;
}
