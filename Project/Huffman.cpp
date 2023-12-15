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

void Select(HuffmanTree HT, int m, int* s1, int* s2)		//��һ��������ѡ��������С����
{	//����m�������ѡ����С��2��//�ѵ�һ�����б�Ǿ�ok 
	int i;//���±�Ϊ1��λ�ÿ�ʼ���� 
	//int min=HT[1].weight;����ֱ�Ӹ�ֵ�����������һ���Ǹ�1������С��ѡѡ�У���ô��2�λ��Ǳ�ѡ�� 
	int min1 = 1000;
	int min2 = 1000;//�涨һ���ر����� 

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
    HT = new HTNode[m + 1];		//0�ŵ�Ԫδ�ã�������Ҫ��̬����m+1����Ԫ��HT[m]��ʾ�����
    for (i = 1; i <= m; ++i)	//��1~m�ŵ�Ԫ�е�˫�ס����ӡ��Һ��ӵ��±궼��ʼ��Ϊ0
    {
        HT[i].parent = 0; HT[i].lchild = 0; HT[i].rchild = 0;
    }
	
//	std::string input;
//	std::getline(std::cin, input);

//	std::istringstream iss(input);
//	int count = 0;
//	while (count < n && iss >> HT[i].zifu >> HT[i].weight) {
//		++count;
	cout << "�������ַ����Ӧ��Ȩֵ��\n";

    for (i = 1; i <= n; ++i)		//����������������Ҷ�ӽ���Ȩֵ
    {
//		scanf("%c=%d", &HT[i].zifu, &HT[i].weight);
		cin >> HT[i].zifu;
		cout << " = ";
		cin >> HT[i].weight;
	}

    for (i = n + 1; i <= m; ++i)	//ͨ��n-1�ε�ѡ��ɾ�����ϲ���������������
    {
        Select(HT, i - 1, &s1, &s2);
        HT[s1].parent = i;			//�õ��½��i����ɭ����ɾ��s1,s2,��s1��s2��˫������0��Ϊi
        HT[s2].parent = i;			
        HT[i].lchild = s1;			//s1��s2�ֱ���Ϊi�����Һ���
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;	//i��ȨֵΪ���Һ��ӵ�Ȩֵ֮��
    }
}

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n)
{
	//��Ҷ�ӵ���������ÿ���ַ��ĺշ������룬�洢�ڱ����HC��
	int i, start, c, f;
	HC = new char* [n + 1];						// ����n���ַ������ͷָ��ʸ��
	char* cd = (char*)malloc(sizeof(char) * n);	// ������ʱ��ű���Ķ�̬����ռ�
	cd[n - 1] = '\0';							// ���������

	for (i = 1; i <= n; ++i)
	{								// ����ַ���շ�������
		start = n - 1;				// start��ʼʱָ����󣬼����������λ��
		c = i;
		f = HT[i].parent;			// fָ����c��˫�׽��
		while (f != 0)
		{							// ��Ҷ�ӽ�㿪ʼ���ϻ��ݣ�ֱ�������
			--start;				// ����һ��start��ǰָһ��λ��
			if (HT[f].lchild == c)
				cd[start] = '0';	// ���c��f�����ӣ������ɴ���0
			else
				cd[start] = '1';	// ���c��f���Һ��ӣ������ɴ���1
			c = f;
			f = HT[f].parent;		// �������ϻ���
		}
		// �����i���ַ��ı���      
		HC[i] = new char[n - start];// Ϊ��i ���ַ��������ռ�
		strcpy(HC[i], &cd[start]);	// ����õı������ʱ�ռ�cd���Ƶ�HC�ĵ�ǰ����
	}

	delete cd;						// �ͷ���ʱ�ռ�                           			
}
