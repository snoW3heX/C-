#ifndef _NODE_LIST_H_
#define _NODE_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "file_handler.h"
 
// 数据结构体 
typedef struct _data{
	// 用户自定义 
	int num;                   	//学号
    char name[10];             	//姓名
    char sex;               	//性别
    int age;           			//年龄
    char mobile[13];           	//手机
    char qq[11];               	//qq号
    char direction[31];         //专业
}DATA;

#define DATA_FROMATE forNode->data.num, forNode->data.name, forNode->data.sex, forNode->data.age, forNode->data.mobile, forNode->data.qq, forNode->data.direction 
#define PF_DATA "%d|%s|%c|%d|%s|%s|%s"

// 链表节点 
typedef struct _node{
	DATA data;
	struct _node *next;
}NODE; 


NODE *createNullList(void);
NODE *createNewNode(DATA tmpData);
// insert
void insertNodeByHead(NODE *headNode, DATA tmpData);
void insertNodeByEnd(NODE *headNode, DATA tmpData);
void insertNodeByPosDataInt(NODE *headNode, int dataId, DATA tmpData);
// delete
int delNodeByPosIndex(NODE *headNode, int posIndex);
int delNodeByPosDataInt(NODE *headNode, int dataId);
int delNodeByPosDataIntRe(NODE *headNode, int dataId);
// update
int updateNodeByPosDataInt(NODE *headNode, int dataId, DATA tmpData);
int updataNodeByPosIndex(NODE *headNode, int posIndex, DATA tmpData);
// search
int searchNodeByPosDataInt(NODE *headNode, int dataId);
int searchNodeByPosIndex(NODE *headNode, int posIndex);
// printall
int printList(NODE *headNode, int mode);

// tools 
NODE *returnFrontEndNode(NODE *headNode);
int freeList(NODE *headNode);
int listIsNull(NODE *headNode);
int listLength(NODE *headNode);
void printFormatInfo(NODE *forNode);

int saveListToHexFile(NODE *headNode, char *filePath);
int loadListFromHexFile(NODE *headNode, char *filePath);

// sort
int listSortFunc(NODE *headNode);


#endif 
