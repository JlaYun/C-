#include <iostream>
#include "ClassInformation.h"
#define  CLASSNUMBER 14     //�γ���

int main() {

    Graph graph, *p; //���´���ͼ
    p = (Graph*)malloc(sizeof(Graph));  //����ռ�
    int TopSort [CLASSNUMBER];
//    graph.ReadClassInformation(p);
    memset(TopSort, 0, sizeof(TopSort));    //��TopSort�еĳ�ʼ��Ϊ0
    selct:
    switch(graph.Menu()){
        case 1:  //1.�ļ���ʽ����γ���Ϣ
        {
            system("cls");        //�����Ļ
            graph.ReadClassInformation(p);
            system("pause");
            system("cls");        //�����Ļ
            goto selct;
        }
        case 2:  //2.�Ӽ��̻�ȡ
        {
            system("cls");        //�����Ļ
            graph.KeyOutput(p);
            system("pause");
            goto selct;
        }
        case 3:  //�޸�
        {

            system("cls");
            graph.Modify_course(p);   //�޸Ŀγ���Ϣ
            system("pause");
            goto selct;
    }
        case 4:  //��ӡ
        {
            system("cls");
            graph.Display_information(p);                        //����γ���Ϣ
            system("pause");
            goto selct;
        }
        case 5:
        {
            system("cls"); //����ѧϰ
            graph.ToplSort(p,TopSort);                        //����γ���Ϣ
            graph.Equality( p,  TopSort);
           // graph.ToplSort(p);
            system("pause");
            goto selct;
        }
        case 6:  //  ����
        {
            system("cls");
            graph.ToplSort(p,TopSort);                        //����γ���Ϣ
            graph.ShortTime( p,TopSort);
            system("pause");
            goto selct;
        }
    }
    cout << "�ڴ����ٴ�ʹ�ã�";
    return 0;
}


