#include <fstream>
#include <iostream>
#include <cstring>
#include <string>

//ģ���ж�����
#define IS_MODULE_HEAD(tmp) (tmp[0]=='$' && tmp[1]=='$' \
				&& tmp[2]=='B' && tmp[3]=='l' \
				&& tmp[4]=='k' && tmp[5]=='D' \
				&& tmp[6]=='e'&&tmp[7]=='f') 
using namespace std;

int main()
{ 
	char *content;
	ifstream fin;//����������
	fin.open("GRID_Export1.dgs");//�ļ���
	char tmp[1000] = {0}; //�洢��ǰ���ַ���
	int i=0;
	int j=0;
	int startindex;//�ַ�����ʼ��
	int endindex;//�ַ�����ֹ��
	int numindex;//�ڼ����ֺ�
	while ( !fin.eof())//��δ�����ļ�β���򡣡���
	{	
		memset(tmp,0,1000);              //��tmp����
		fin.getline(tmp,1000);           //��ȡһ������
		if (IS_MODULE_HEAD(tmp))
		{
			for(j=0;j<14;j++)//����ģ��ͷ��˵�����֣�ѭ���峤��=ģ��ͷ������+1
			{
				memset(tmp,0,1000);  
				fin.getline(tmp,1000);
			}
			while(tmp[0]!='$')//����ģ�����ֹ����==������һģ��ͷ�ĵ�һ���ַ�
			{
				startindex=2;
				endindex=0;
				numindex=0;
				for(int i=0;i<1000;i++)//������
				{
					if(tmp[i]==';')
					{
						endindex=i;
						numindex++;
						if(numindex==3)//����Ҫ����������Ϊ��
						{
							content=new char[endindex-startindex-1];//��Ҫ�������ݴ���content��
							int mm=0;
							for(j=startindex+1;j<endindex;j++)//��content��ֵ����ʾcontent����
							{
								content[mm]=tmp[j];
								cout<<content[mm];
								mm++;
							}
							cout<<endl;
						}
						startindex=endindex;
					}
				}
				memset(tmp,0,1000);              //��tmp����
				fin.getline(tmp,1000);           //����һ������
			}
		}
	}
	fin.close();
	delete(content);
//	cin.get();
}
