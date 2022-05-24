//
// Created by Ao-jiayun on 2022/5/10.
//

#ifndef EX_CLASSINFORMATION_H
#define EX_CLASSINFORMATION_H
#include <fstream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define COURSE_MAX_NUMBER 20                                       //���γ̸���

#define MaxClass 100		//�γ�����������100
#define MaxSemester 12		//ѧ������������12

typedef   int  Elemtype;

//�γ̽ṹ��
struct Course
{
    char id[10];            //�γ̱��
    char name[30];           //�γ�����
  //  string name[20];
    int credit;                 //�γ�ѧ��
    bool course_exist;             //�жϵ�ǰ�γ��Ƿ����
    int SemesterNum;		//ѧ����
    int MaxCredit;		//ÿѧ��ѧ������
    int  ClassSum=0; //�γ�����
    int Apcourse =0;  //���޿γ���
};
//ջ
typedef struct {
    Elemtype data[MaxClass];
    int top;
    int length;
}SqStack;

class Graph{
public:
    void Equality(Graph* p, int TopSort[]);
    void ToplSort(Graph* p,int TopSort[]); ////������������
    //void ToplSort(Graph* p); ////������������
    // void CreatTable(ALGraph* G,Graph* p);
    void ShortTime(Graph* p, int TopSort[]);
    void TwoTactics(Graph* p);      //���ֱ��Ų���
    bool ReadClassInformation( Graph* p);    //��ȡ�ļ��е���Ϣ
    void KeyOutput(Graph* p);                    //�Ӽ�������γ���Ϣ
    void Modify_course(Graph* p);             //�޸Ŀγ�
    void Display_information(Graph* p);        //����γ���Ϣ
    int Menu();


private:
         SqStack sqStack;
       // LinkNode linkNode;      ////��ջ
        Course course[COURSE_MAX_NUMBER];       //��಻����100    //�γ���Ϣ
        int course_number;//�γ�����
        int Adjmatrix[COURSE_MAX_NUMBER][COURSE_MAX_NUMBER];      //�ڽӾ����ſγ�֮��Ĺ�ϵ


};
#endif //EX_CLASSINFORMATION_H
