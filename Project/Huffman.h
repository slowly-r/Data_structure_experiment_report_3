#pragma once

#ifndef HUFFMAN_H
#define HUFFMAN_H

#define To(a,b) a=b
#define Equal(a,b) a==b
#define Sense(i) i==0
#define Small(i,j) i<j
#define NEqual(a,b) a!=b
#define uint unsigned int

//---------���������Ĵ洢��ʾ---------����������
typedef struct {
    char zifu;
    int weight;                     //����Ȩֵ
    int parent, lchild, rchild;     //����˫�ס����ӡ��Һ��ӵ��±�
}HTNode, * HuffmanTree;             //��̬��������洢��������

enum { MAX = 65536 };

typedef char** HuffmanCode;

void Select(HuffmanTree HT, int* min1, int* min2);
void CreateHuffmanTree(HuffmanTree& HT, int n);
void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n);

#endif 


