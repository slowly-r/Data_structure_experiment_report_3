#pragma once

#ifndef HUFFMAN_H
#define HUFFMAN_H

#define To(a,b) a=b
#define Equal(a,b) a==b
#define Sense(i) i==0
#define Small(i,j) i<j
#define NEqual(a,b) a!=b
#define uint unsigned int

//---------哈夫曼树的存储表示---------（最优树）
typedef struct {
    char zifu;
    int weight;                     //结点的权值
    int parent, lchild, rchild;     //结点的双亲、左孩子、右孩子的下标
}HTNode, * HuffmanTree;             //动态分配数组存储哈夫曼树

enum { MAX = 65536 };

typedef char** HuffmanCode;

void Select(HuffmanTree HT, int* min1, int* min2);
void CreateHuffmanTree(HuffmanTree& HT, int n);
void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n);

#endif 


