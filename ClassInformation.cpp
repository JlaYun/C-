//
// Created by Ao-jiayun on 2022/5/10.
//

#include <stack>
#include "ClassInformation.h"


bool Graph::ReadClassInformation( Graph *p) {
   // int choose=0;
    //ifstream file2("c://pdos.def");       //�����뷽ʽ���ļ�
    //ofstream file3("c://x.123");          //�������ʽ���ļ�
    // file1.close();�Ͱ�file1�������ļ��ر�

    std::ifstream in("E:\\S-ata-strcture\\Ex\\cmake-build-debug\\new 2.txt");
    if (!in.is_open()) {     //!is_open() �ж��ļ��Ƿ����
        cout << "�ļ������ڣ�" <<endl;
        cout << "�����ļ��н���" << endl;
        in.close();
        return false;
    }
    //���ļ��л�ȡ��������飬��Ӧ�γ̱�š��γ�����ѧ��
    in >> p->course_number;   //�������

    cout<<"������Ϣ����"<<endl;
    // system("cls");      //������������
    for (int i = 1;i <= p->course_number;i++)
    {

        in >> p->course[i].id;
        in>> p->course[i].name ;
        in>>p->course[i].credit;
        cout<<"��"<<i<<"�ſγ̱���ǣ�"<<p->course[i].id<<endl;
        cout<<"�γ����ǣ�"<<p->course[i].name<<endl;
        cout<<"ѧ���ǣ�"<<p->course[i].credit<<endl;
        p->course[i].course_exist = true;
    }
    //����γ���Ϣ
    int i, j;
    for (int k = 0;k < p->course_number;k++)   //���ļ�����Ϣ����    Adjmatrix ��
    {
        in >> i >> j;
        p->Adjmatrix[i][j] = 1;                   //��ʾ�γ�ci�ǿγ�cj�����޿γ�

        }
//    for (int i = 1;i <= p->course_number;i++)
//    {
//        for (int j = 1;j <= p->course_number;j++)
//            cout <<std::setw(4)<< p->Adjmatrix[i][j] << " ";  //�ڽӾ���
//        cout << endl;
//    }
    in.close();
    cout << "�ļ�����Ŀγ���Ϣ�ѳɹ�¼�룡" << endl;
    }



//������ʽ����γ���Ϣ����ͼ
//�������  1��ѧ������ 2��һѧ�ڵ�ѧ������ 3���γ̱�� 4��ѧ�� 5��ֱ�����޿γ̱��
void Graph::KeyOutput(Graph* p){
     //ALGraph *G;
   // p->ALGRAPHS.ExtraInfo = (Message*)malloc(sizeof(Message));		//��ʼ��ָ��
    system("cls");        //�����Ļ
    // cout << " ѧ������(�м���ѧ��)  ÿѧ��ѧ������  һѧ�ڿγ�������ÿѧ��*�γ̣�" << endl<<endl;
   //  scanf("%d%d%d",&p->course->SemesterNum,&p->course->MaxCredit,&p->course->ClassSum);
        cout<<" ѧ������(�м���ѧ��)"<<endl;
        cin>>p->course->SemesterNum;
         cout<<" ÿѧ��ѧ������"<<endl;
         cin>>p->course->MaxCredit;
         cout<<" һѧ�ڿγ�����������Ϊ��ÿѧ��*�γ̣�"<<endl;
         cin>>p->course->ClassSum;
    if (p->course->ClassSum > MaxClass) {                          // //MaxClassΪѧ������
        printf("�������γ�����%d,���������\n", MaxClass);
        exit(1);
    }
    if (p->course->SemesterNum > MaxSemester) {  //SemesterNum ѧ����
        printf("�������ѧ����%d,���������\n", MaxSemester);
        exit(1);   //�˳� ��return -- exit
    }
  //  cout << "������γ�����" << endl;
  //  cin >> p->course_number;  //�Ӽ�������
//    system("cls");        //�����Ļ
//    system("pause");
    cout << "������γ�������"<<(p->course->SemesterNum * p->course->ClassSum) << endl;
//    printf("���������޿�ֱ������ <0>"); cout<<endl;
    printf("��������γ̣��������� <0>"); cout<<endl;  //���̻�ȡ���޿���Ϣ
    printf("��Ҫѧϰ�Ŀγ���Ϊ:");
    cin >> p->course_number;  //��ȡ���޵Ŀγ���Ŀ
    p->course->Apcourse=p->course_number;  //����ṹ����
    if(p->course_number==0) {
        printf("��û������γ���Ϣ");
       // printf("�����´��ļ�����γ���Ϣ");
       // ReadClassInformation( p); //���µ�����Ϣ
        return;
    }
    int tag=0;
    cout << "����������γ̱�š��γ����ƺ�ѧ��" << endl;
    system("pause");    //�밴���������. . .
    for (int i = 1;i <= p->course_number;i++)
        {
            cout << "��" << i << "�ŵ�";
            cout << "�γ̱���ǣ�";
            cin >> p->course[i].id;
            cout << "�γ������ǣ�";
            cin >> p->course[i].name;
            cout << "�γ̷����ǣ�";
            cin >> p->course[i].credit;  // �γ̱�š��γ����ƺ�ѧ��
          //  grade += p->course[i].credit;

            p->course[i].course_exist = true;
            }
    printf("�������޿ε�ֵ�ǣ�%d",p->course_number);
    cout<<endl;
    memset(p->Adjmatrix, 0, sizeof(p->Adjmatrix));    //��ʼ��adjmatrixȫ��Ԫ��Ϊ0
    cout << "������γ�֮���ǰ���ϵ:����������(�ɿγ̱��ȷ�� ÿ������һ����)" << endl;
    printf("���� 1  2 �γ�1��2�ı��޿�");cout<<endl;
    cout<<endl;
        ////���ݿγ̽����ڽӱ��� �ļ���δ�رգ����α�����������һ�������
      int i, j, k;
    for (k = 1; k<=p->course_number/2;k++)
    {
        cin >> i >> j;
        p->Adjmatrix[i][j] = 1;   //��ʾ�γ�ci�ǿγ�cj�����޿γ�
    }
    cout << "��������Ŀγ���Ϣ�ѳɹ�¼�룡" << endl;
}


////���ýṹ�彨���ڽӾ���
//void Graph::CreatTable(ALGraph* G ,Graph* p ){
//
//    G->VexNum=p->course->ClassSum;  //��ȡ�޸ĵ����γ���
//    FILE* fp = fopen("E:\\S-ata-strcture\\Ex\\cmake-build-debug\\new 2.txt", "r");
//    if (NULL == fp) {
//        printf("�ļ�·�����󣡣���");
//        exit(1);
//    }
//    G->Vertics = (VexNode*)malloc(sizeof(VexNode) * G->VexNum);
//    for (int i = 0; i < G->VexNum; i++)
//        G->Vertics[i].FirstEdge = NULL;		//��ʼ��
//    for (int i = 0; i < G->VexNum; i++) {		//��ȡ�γ���Ϣ
//        fscanf(fp, "%s%d", G->Vertics[i].Date, &G->Vertics[i].Credit);		//��ȡ�γ����ƺ�ѧ��
//        while ('\n' != fgetc(fp)) {		//�������޿γ̽����ڽӱ���
//            char str[4];
//            int s;
//            fscanf(fp, "%s", str);
//            s = Locate(str);
//            if (s < 0 || s > G->VexNum) {		//�жϿγ��Ƿ��д���
//                printf("%s�������\n", G->Vertics[i].Date);
//                exit(1);
//            }
//            EdgeNode* p = (EdgeNode*)malloc(sizeof(EdgeNode));		//�����ڽӱ���
//            p->AdjVex = i;
//            p->Next = G->Vertics[s].FirstEdge;
//            G->Vertics[s].FirstEdge = p;
//            G->ArcNum++;
//        }
//    }
//    fclose(fp);
//    for (int i = 0; i < G->VexNum; i++)		//�������
//        G->Vertics[i].InDegree=0;
//    for (int i = 0; i < G->VexNum; i++) {
//        for (EdgeNode* p = G->Vertics[i].FirstEdge; NULL != p; p = p->Next) {
//            G->Vertics[p->AdjVex].InDegree++;
//        }
//
//    }
//}

//����γ���Ϣ
void Graph::Display_information(Graph* p) {
    int Choice = 0;
    printf("��������Ҫ�������Ϣ�� 1���γ���Ϣ��  2�����γ̵��Ⱥ�˳��");
    cout << endl;
    cin >> Choice;
    if (p->course->Apcourse== 0&& p->course_number==0 ) {
        printf("û�л�ȡ���γ���Ϣ");
        cout << endl;
        return;
    }
    if (Choice == 1) {

        cout << "�γ���Ϣ���£�" << endl;
        cout << "�γ̱�� " << "�γ����� " << "         �γ�ѧ��   " << endl;
        for (int i = 1; i <= p->course_number; i++) {
            cout << std::setw(5) << p->course[i].id << "  \5";
            cout << p->course[i].name << " ";
            cout << p->course[i].credit << std::setw(5) << " ";
            cout << endl;
        }
    }
    if (Choice == 2) {
        cout << endl << "�γ̹�ϵ����(���Ϊ��Ӧ1-" << p->course_number<< "�ſγ�,�γ̴� 1 ��ʼ)" << endl;
        for (int i = 0; i <= p->course_number; i++) {
            if (i >= 10)
                cout << i << std::setw(6);
            else cout << i << std::setw(4);
        }
        cout << endl;//���1-14
        for (int i = 0; i <= 14; i++) {
            cout << "----" << std::setw(4);//-------------
        }
        cout << endl;
        for (int i = 1; i <= p->course_number; i++) {
            for (int j = 1; j <= p->course_number; j++)
                cout << std::setw(4) << p->Adjmatrix[i][j] << " ";  //�ڽӾ���
            cout << endl;
        }
    }
    if(Choice!=1&&Choice!=2)
    {
        printf("���������������");
        cout<<endl;
            return;
}
}
//�޸Ŀγ���Ϣ
void Graph::Modify_course(Graph* p)
{
    //�޸�֮ǰ�����жϸÿγ̱���Ƿ����ļ���
    int number=0,choice;
    string input ,Str;
    int temp=0;
    bool Ex= true;
    int tag=0;
    do{
        cout << "�����������޸ĵĿγ̱�ţ�" << endl;
        cin >> input;
        cout<<endl;
        while(!tag){
            for (int i = 1; i <= p->course_number; i++){
                Str = p->course[i].id;
                temp++;
                    //int strcmp(const char *input, const char *Str); //strcmp �ж��Ƿ���� ��� Ϊ 0
            if(input==p->course[i].id){
                  printf("��Ҫ�޸ĵĿγ̴���");
                number= temp;
                  tag=1;
                                }
                }
              if(tag==0)
              { printf("�ÿγ̲�����");
                  return;
              }
        }
        cout<<endl;
     //   printf("�γ�λ���±꣺%d",number); cout<<endl;

      //  cout<<number<<endl;
        cout << "�����޸ĵ���ϢΪ(1.�γ����� 2.�γ�ѧ��)��" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "�������µĿγ�����" << endl;
            cin >> p->course[number].name;
        }
        if (choice == 2)
        {
            cout << "�������µĿγ�ѧ��" << endl;
            cin >> p->course[number].credit;
        }
        cout << "�޸ĳɹ�" << endl;
        Ex= false;



//    for (int i = 1; i <= p->course_number; i++) {
//            Str = p->course[i].id;
//            int strcmp(const char *input, const char *Str);
//            //if ((input.compare(p->course[i].id))){  //��ͬΪ0
//            cout << strcmp << endl;
////           if(strcmp==0){
//
//            if(input==p->course[i].id){
////            cout<<"����γ̱��"<<p->course[i].id<<endl;
//                printf("��Ҫ�޸ĵĿγ̴���");
//            cout<<endl;
            // ȥ��C ��������
//                for (int q = 1; q < input.length(); q++)    //�����c��ͷ
//                {
//                    if (input[q] >= '0'&&input[q] <= '9')
//                    {
//                        temp += input[q];
//                    }
//                }
//                number= temp;
//                cout<<number<<endl;
//                cout << "�����޸ĵ���ϢΪ(1.�γ����� 2.�γ�ѧ��)��" << endl;
//                cin >> choice;
//                if (choice == 1)
//                {
//                    cout << "�������µĿγ�����" << endl;
//                    cin >> p->course[number].name;
//                }
//                if (choice == 2)
//                {
//                    cout << "�������µĿγ�ѧ��" << endl;
//                    cin >> p->course[number].credit;
//                }
//                cout << "�޸ĳɹ�" << endl;
//                Ex= true;
//            }
//            printf("����������");


    }while (Ex);

}
void InitStack(SqStack &s){
    s.top=-1;
    printf("��ʼ�����SqStack ");    cout<<endl;
}
//��ջ
bool StakEmpty(SqStack &s,Elemtype x){
//    InitStack(s);
//    s.top=-1;
    if(s.top==MaxClass-1)return false;
    printf("��ջͷ�ǣ�%d",s.top);    cout<<endl;
    cout<<endl;
    s.top+=1;
    s.data[s.top]=x;
//    printf("��ջ");
//    cout<<"--ֵ��"<<x<<endl;
    s.length++;
    return true;
}
//��ջ
bool Pop(SqStack &s,Elemtype *x){
    if(s.top==-1)return false;
//    printf("��ջͷ�ǣ�%d",s.top);   cout<<endl;
    *x=s.data[s.top--];
 //   printf("��ջֵ��%d ",x);    cout<<endl;
    return true;
}
//��ֵ
bool GetTop(SqStack &s){
    if(s.top==-1)return false;
    printf("��ȡֵʱջͷ�ǣ�%d",s.top);     cout<<endl;
    s.data[s.top];
    cout<<"��ȡֵ ��"<< s.data[s.top]<<endl;
    s.top--;
    return true;
}
//������������

//void Graph::ToplSort(Graph* p,int TopSort[]) {
//
//   SqStack *S;
//    S= (SqStack*)malloc(sizeof(SqStack));  //����ռ�
//    InitStack(*S);
//    cout<<endl;
//    cout<<"��ȡͷָ��"<<S->top<<endl;
//    int indegree[p->course_number + 1];               //��Ÿ�������ȣ���indegree[1]��ʼ��ţ�
//    memset(indegree, 0, sizeof(indegree));          //��indegreeȫ����ֵΪ0
// //   for(int i=0;i<p->course_number;i++)cout<<indegree[i]<<"--"<<endl;         //   ȫ0
//    for (int i = 1;i <= p->course_number;i++)     //ͳ�Ƹ��������
//        for (int j = 1;j <= p->course_number;j++)
//            if (p->Adjmatrix[i][j]) indegree[j]++;
//   // for(int i=0;i<p->course_number;i++)cout<<indegree[i]<<"-***-"<<endl;         //   ȫ0
//    for (int i = 1; i <= p->course_number; i++)   //���Ϊ0����ѹ��ջ
//    {
//        if (!indegree[i]) {     // 1��8��9
//            // printf("�������н�ջ"); //��iֵ��ջ
//            StakEmpty(*S, i);        //��ջ
//         //   cout << "StakEmpty һ����ջ  --" << i << endl;
//
//        }
//    }
//    cout<<"���λ�ȡͷָ��"<<S->top<<endl;   // 2
//    int touz=S->top;
//    int num=0, t;
//    while(S->top!=0){  // �ǿ�
//        printf("�����ж�");
//        int TopEle;
//      //  for(int i=S->length;i>=0;i--)  //length=2
//        Pop(*S,&t); //��ȡջ��Ԫ�� ��ջ
//        TopEle=t; cout<<endl;   //��ȡջ�е�ֵ 9 8 1
//        printf("TopEle��ֵ�ǣ�%d",TopEle);   cout<<endl;
//        TopSort[num]=TopEle;  //��Ԫ�� (9 8 1)����TS����
//       printf("TopSort��ֵ%d",TopSort[num]);
//        num++;
//        for(int j=0;j<p->course_number;j++){
//            if(p->Adjmatrix[TopEle++][0]){
//                if(!--indegree[0])
//                    StakEmpty(*S,j);
//                cout << "StakEmpty ������ջ  --" << j << endl;  //12 13
//
//            }
//        }
//    }
//
//    }

//������������

void Graph::ToplSort(Graph* p, int TopSort[])
{
    int indegree[p->course_number + 1];           //��Ÿ�������ȣ���indegree[1]��ʼ��ţ�
    memset(indegree, 0, sizeof(indegree));
    for (int i = 1;i <= p->course_number;i++)     //ͳ�Ƹ��������
        for (int j = 1;j <= p->course_number;j++)
            if (p->Adjmatrix[i][j]) indegree[j]++;

    stack <int> s;  //����ջ
    for (int i = 1;i <= p->course_number;i++)     //���Ϊ0����ѹ��ջ
        if (!indegree[i]) s.push(i);                //push() ��ջ������Ԫ��

    int num = 0;                                  //��ʼ������������
    while (!s.empty())            //ջ�ǿ� ��Ϊ�ж������Ƿ�Ϊ�յĺ�����
    {
        int top;
        top = s.top();                            //ȡջ��Ԫ��
        s.pop();                                  //��ջ
        TopSort[num++] = top;       //����ջ��Ԫ��
        for (int j = 1;j <= p->course_number;j++)
        {
            if (p->Adjmatrix[top][j])
            {
                if (!--indegree[j]) s.push(j);    //ÿ��һ��Ԫ�أ�����ָ��Ľ����ȼ�1
            }                                     //���ж��Ƿ�Ϊ0����Ϊ������ջ
        }
    }
}

//����ѧ���е�ѧϰ�����������ȵ��ƶ���ѧ�ƻ�
void Graph::Equality(Graph* p, int TopSort[])
{
    //�����ļ���
    ofstream out("Equality-class.txt");
    int average_credit = 0;
    int semester=0;  //ѧ����
    for (int i = 1;i <= p->course_number;i++)     //����γ���ѧ��
    {
        average_credit += p->course[i].credit;
    }
    printf("�ܷ���:%d",average_credit); cout<<endl;
    int remaine_credit = average_credit;          //remaining_creditΪʣ����ѧ��
    semester=p->course->SemesterNum;                //��ȡ�ϴӼ��̻�ȡ��ѧ����Ŀ
    if(semester==NULL){
        printf("��û������ѧ����Ŀ������Ĭ��ֵ8����");    //4����
        cout<<endl;
        average_credit /= 8;     //���蹲8��ѧ��
    }
    else   average_credit /=semester;
    out << "ƽ��ѧ��Ϊ:" << average_credit << endl << endl;
    int term_number = 1, j = 0;                   //ѧ�ڱ�š��������е��±�
   // printf("ʣ���ܷ���%d",remaine_credit);  cout<<endl;
    while (remaine_credit > 0)                    //��ѧ�ֻ�ʣ��
    {
        int term_credit = 0;
        int term_remaine_credit = average_credit; //��ǰѧ�ڻ����޵�ѧ��  -- ��ȡÿѧ�ڵ�ƽ��ѧ��
        out << "��" << term_number << "ѧ��:" << endl;
        if (remaine_credit > term_remaine_credit) //ʣ����ѧ�ֶ��ڵ�ǰѧ�ڻ����޵�ѧ��
        {
            while (term_remaine_credit > 0)       //��ǰѧ�ڻ����޵�ѧ�ֻ�ʣ��
            {
                out << p->course[TopSort[j]].id << " ";     //j Ϊ0 ��Ϊ��ջΪ0�Ľڵ�
                out << p->course[TopSort[j]].name << " ";
                out << p->course[TopSort[j]].credit << " ";

                term_remaine_credit -= p->course[TopSort[j]].credit;
                remaine_credit -= p->course[TopSort[j]].credit;
                term_credit += p->course[TopSort[j]].credit;
                j++;
                out << endl;
            }
            term_number++; //��ǰѧ��û�л����޵�ѧ�֣�����ѧ��
        }
        else  //ʣ����ѧ�����ڻ���ڵ�ǰѧ�ڻ����޵�ѧ��
        {
            out << p->course[TopSort[j]].id << " ";
            out << p->course[TopSort[j]].name << " ";
            out << p->course[TopSort[j]].credit << " ";

            term_remaine_credit -= p->course[TopSort[j]].credit;  //��ǰѧ��ѧ�ּ�ȥ��ǰѧ�Ƶ�ѧ��
            remaine_credit -= p->course[TopSort[j]].credit;   //��ѧ�ּ�ȥ��ǰѧ�Ƶ�ѧ��
            term_credit += p->course[TopSort[j]].credit;  //��ǰѧ�ڵķ���
            j++;
            out << endl;
        }
        out << "��ѧ����ѧ��Ϊ��" << term_credit << endl << endl;
    }
    out << "ѧ������Ϊ:" << term_number << endl;
    out.close();
    cout << "��ѧ�ƻ��ѱ��浽�ļ�Equality-class.txt ��" << endl;
}

// ���̵ܶ�ʱ�����ѧϰ�ƶ���ѧ�ƻ�
void Graph::ShortTime(Graph* p, int TopSort[]) {
    ofstream out("FinishTheProjectShort.txt");
    int term_credit;                              //ѧ����ѧ��
    int term_number = 1;                          //ѧ�ڱ��
    int number = 0;                               //�����������±�
    int remain_credit = 0;                        //ʣ����ѧ��
    int EachCredit = 0;
    for (int i = 1; i <= p->course_number; i++)     //����γ���ѧ��
    {
        remain_credit += p->course[i].credit;
    }

    EachCredit = p->course->MaxCredit;  //��ȡ�������õ�ÿѧ��ѧ������
    // cout<<"û������ѧ����EachCredit��ֵ�ǣ�"<<EachCredit<<endl;  // û�н��пγ̵�������Ϊ0
   // printf("�ܷ��ǣ�%d",remain_credit);
    if (EachCredit == 0) {
        printf("û������ÿѧ�ڵ�ѧ�֣�Ĭ������Ϊ12");
        while (remain_credit > 12)   //ÿѧ��ѧ������Ϊ12
        {
            term_credit = 0;
            out << "��" << term_number << "ѧ��:" << endl;
            while (term_credit + p->course[TopSort[number]].credit < 12) {    //��ǰ��ѧ����ѧ��+��һ��Ҫ���ſγ̵�ѧ��<ѧ������12
                out << p->course[TopSort[number]].id << " ";
                out << p->course[TopSort[number]].name << " ";
                out << p->course[TopSort[number]].credit << " " << endl;
                term_credit += p->course[TopSort[number]].credit;
                remain_credit -= p->course[TopSort[number]].credit;
                number++;
            }
            term_number++;
            out << "��ѧ����ѧ��Ϊ��" << term_credit << endl << endl;

            term_credit = 0;
            out << "��" << term_number << "ѧ��:" << endl;//��ѧ��ʣ��С��12ʱ
            while (remain_credit > 0) {
                out << p->course[TopSort[number]].id << " ";
                out << p->course[TopSort[number]].name << " ";
                out << p->course[TopSort[number]].credit << " " << endl;
                term_credit += p->course[TopSort[number]].credit;
                remain_credit -= p->course[TopSort[number]].credit;
                number++;
            }
            out << "��ѧ����ѧ��Ϊ��" << term_credit << endl << endl;
            out << "ѧ������Ϊ:" << term_number << endl;
            out.close();
            cout<<endl;
            cout << "��ѧ�ƻ��ѱ��浽�ļ�--Finish the project short.txt��" << endl;
        }
    }
    else {
        while (remain_credit > EachCredit)   //ÿѧ��ѧ������Ϊ12
        {
            term_credit = 0;
            out << "��" << term_number << "ѧ��:" << endl;
            while (term_credit + p->course[TopSort[number]].credit < 12)
            {    //��ǰ��ѧ����ѧ��+��һ��Ҫ���ſγ̵�ѧ��<ѧ������12
                out << p->course[TopSort[number]].id << " ";
                out << p->course[TopSort[number]].name << " ";
                out << p->course[TopSort[number]].credit << " " << endl;
                term_credit += p->course[TopSort[number]].credit;
                remain_credit -= p->course[TopSort[number]].credit;
                number++;
            }
            term_number++;
            out << "��ѧ����ѧ��Ϊ��" << term_credit << endl << endl;
        }
        term_credit = 0;
        out << "��" << term_number << "ѧ��:" << endl;//��ѧ��ʣ��С��12ʱ
        while (remain_credit > 0)
        {
            out << p->course[TopSort[number]].id << " ";
            out << p->course[TopSort[number]].name << " ";
            out << p->course[TopSort[number]].credit << " " << endl;
            term_credit += p->course[TopSort[number]].credit;
            remain_credit -= p->course[TopSort[number]].credit;
            number++;
        }
        out << "��ѧ����ѧ��Ϊ��" << term_credit << endl << endl;
        out << "ѧ������Ϊ:" << term_number << endl;
        out.close();
        cout << "��ѧ�ƻ��ѱ��浽�ļ�--Finish the project short.txt��" << endl;
    }
}
//����˵�
int Graph::Menu()
{
    int i;
    do {
        system("cls");
        cout << "***************��ѧ�ƻ�����ϵͳ****************" << endl << endl;
        cout << "           1.�ļ���ʽ����γ���Ϣ" << endl;
        cout << "           2.������ʽ����γ���Ϣ" << endl;
        cout << "           3.�γ���Ϣ�޸�" << endl;
        cout << "           4.�γ���Ϣ���" << endl;
        cout << "           5.����ѧ���е�ѧϰ�����������ȵ��ƶ���ѧ�ƻ�" << endl;
        cout << "           6.�������̵ܶ�ʱ�����ѧϰ�ƶ���ѧ�ƻ�" << endl;
        cout << "           7.�˳�����" << endl << endl;
        cout << "********************************************" << endl << endl;
        cout << "           ����������ѡ��";
        cin >> i;

    } while (i < 1 || i>7);
    return i;
}
