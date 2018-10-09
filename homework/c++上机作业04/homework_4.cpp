#include<bits/stdc++.h>
using namespace std;
class DNode
{
private:
    int x,y;
    DNode *left,*right;
public:
    DNode(int xx=0,int yy=0,DNode *templeft=NULL,
          DNode *tempright=NULL);
    void setDNodeValues(int tx,int ty);
    void insertLeft(DNode *x=NULL);
    void insertRight(DNode *x=NULL);
    void deleteNode(void);
    DNode *nextNodeLeft(void);
    DNode *nextNodeRight(void);
    void printNode(void);
};
DNode::DNode(int xx,int yy,DNode *tl,DNode *tr)
{
    x=xx,y=yy,left=tl,right=tr;
}

void DNode::setDNodeValues(int tx,int ty)
{
    x=tx,y=ty;
}

void DNode::insertLeft(DNode *x)
{
    left=x;
}

void DNode::insertRight(DNode *x)
{
    right=x;
}

void DNode::deleteNode(void)
{
    if(left!=NULL && right!=NULL)
    {
        left->insertRight(right);
        right->insertLeft(left);
    }
    else if(left!=NULL)
        left->insertRight(NULL);
    else
        right->insertLeft(NULL);
}

DNode * DNode::nextNodeLeft(void)
{
    return left;
}

DNode * DNode::nextNodeRight(void)
{
    return right;
}

void DNode::printNode(void)
{
    cout<<"("<<x<<","<<y<<")"<<endl;
}

int main ()
{
    DNode a[4];

    for(int i=0;i<4;i++)
    {
        a[i].setDNodeValues(i+1,i+2);
        int l=i-1,r=i+1;
        if(l>=0 && l<=3)
            a[i].insertLeft(&a[l]);
        if(r>=0 && r<=3)
            a[i].insertRight(&a[r]);
    }

    for(int i=0;i<4;i++)
    {
        cout<<"��"<<i+1<<"�������";
        a[i].printNode();
        if(a[i].nextNodeLeft()!=NULL)
        {
            cout<<"��"<<i+1<<"������������";
            a[i].nextNodeLeft()->printNode();
        }
        else
            cout<<"��"<<i+1<<"�����������ǿս��"<<endl;
        if(a[i].nextNodeRight()!=NULL)
        {
            cout<<"��"<<i+1<<"�������ҽ����";
            a[i].nextNodeRight()->printNode();
        }
        else
            cout<<"��"<<i+1<<"�������ҽ���ǿս��"<<endl;
        cout<<endl;
    }

    cout<<"ɾ����2������\n"<<endl;
    a[1].deleteNode();

    for(int i=0;i<4;i++)
    {
        cout<<"��"<<i+1<<"�������";
        a[i].printNode();
        if(a[i].nextNodeLeft()!=NULL)
        {
            cout<<"��"<<i+1<<"������������";
            a[i].nextNodeLeft()->printNode();
        }
        else
            cout<<"��"<<i+1<<"�����������ǿս��"<<endl;
        if(a[i].nextNodeRight()!=NULL)
        {
            cout<<"��"<<i+1<<"�������ҽ����";
            a[i].nextNodeRight()->printNode();
        }
        else
            cout<<"��"<<i+1<<"�������ҽ���ǿս��"<<endl;
        cout<<endl;
    }

    cout<<"ע��ڶ������ɾ���󣬵�һ�������ҽ��仯�͵�������������仯"<<endl;
    return 0;
}
