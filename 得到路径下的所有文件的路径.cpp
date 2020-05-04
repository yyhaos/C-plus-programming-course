#include<bits/stdc++.h>
#include<io.h>
using namespace std;
void getFiles(string path, vector<string>& files)	//得到测试用的文件目录集 保存在files里
{
	//files.clear();
	long long   hFile = 0;
	struct _finddata_t fileinfo;
	string p;
	cout << p.assign(path).append("\\*").c_str() << endl;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{

			if ((fileinfo.attrib &  _A_SUBDIR))
			{//cout<<p.assign(path).append("\\").append(fileinfo.name)<<endl;
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);
	}
}
int main ()
{
    while(1){


    string str;

    if(str=="1")
        break;
    cin>>str;
    vector<string > tmp;
    getFiles(str,tmp);
    for(int i=0;i<tmp.size();i++)
    {
        cout<<i<<" : "<<tmp[i]<<endl;
    }
    }

}
