
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ifstream OpenFile("in.txt");    //�����ļ������ֲ�ͬ�Ķ���
    ofstream SaveFile("out.txt");
    int n;
    while(OpenFile>>n)
    {
        int score[n];
        //int * score =new int[n];  //Ҳ������new������
        for(int i=0;i<n;i++)
        {
            OpenFile>>score[i];
        }
        for(int i=0;i<n;i++)    // ʹ��ð������
        {
            for(int j=n-1;j>=i;j--)
            {
                if(score[j]>score[j+1])
                {
                    int tem=score[j];
                    score[j]=score[j+1];
                    score[j+1]=tem;
                }
            }
        }
        SaveFile<<n;
        for(int i=0;i<n;i++)
        {
            SaveFile<<" "<<score[i];
        }
        SaveFile<<endl;
    }
    OpenFile.close();
    SaveFile.close();
    cout<<"finished"<<endl;
    return 0;
}
