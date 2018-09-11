
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ifstream OpenFile("in.txt");    //两种文件有两种不同的定义
    ofstream SaveFile("out.txt");
    int n;
    while(OpenFile>>n)
    {
        int score[n];
        //int * score =new int[n];  //也可以用new来定义
        for(int i=0;i<n;i++)
        {
            OpenFile>>score[i];
        }
        for(int i=0;i<n;i++)    // 使用冒泡排序
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
