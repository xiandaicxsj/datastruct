#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
string DelStr(int playerNum,int testNum,string testStr,map<string,string>&map_str);
int main()
{
		int testNum=0;
		cin>>testNum;
		string *ret=new string[testNum];
		int i=0;
		int playerNum=0;
		int tranferNum=0;
		map<string,string> map_str;
		for(i=0;i<testNum;i++)
		{
				cin>>playerNum;
				cin>>tranferNum;
				string baseStr;
				string transStr;
				string testStr;
				for(int j=0;j<tranferNum;j++)
				{
					cin>>baseStr;
					cin>>transStr;
					map_str[baseStr]=transStr;
				}
				getline(cin,testStr);
				getline(cin,testStr);
				ret[i]=DelStr(playerNum,testNum,testStr,map_str);
				map_str.clear();
		}
		for(i=0;i<testNum;i++)
		{
				cout<<"Case ";
				cout<<"#";
				cout<<i+1;
				cout<<": ";
				cout<<ret[i]<<endl;
		}
			
}
void showVec(vector<string> t)
{
	cout<<"showVec"<<endl;
		vector<string>::iterator a=t.begin();
		for(;a<t.end();a++)
		{
				cout<<*a;
				cout<<endl;
		}
		cout<<"showEnd"<<endl;
}
vector<string> StrSplit(string testStr)
{
	vector<string> result;
	int i=0;
	int j=0;
	string tmp;
	int len=testStr.length();
		while(i<len)
		{
				tmp="";
				while(j<len&&testStr[j]!=' ')
				{
					tmp=tmp+testStr[j];
					j++;
				}
				if(j<len&&testStr[j]==' ')
				{
					result.push_back(tmp);
					while(j<len&&testStr[j]==' ')
					j++;
				}
				if(j==len)
				{
						result.push_back(tmp);
						break;
				}
				i=j;
		}
		return result;

}
string DelStr(int playerNum,int testNum,string testStr,map<string,string>&map_str)
{
		vector<string> strVec=StrSplit(testStr);
		for(int i=0;i<playerNum-1;i++)
		{
				map<string,string>::iterator mapIter;
				vector<string>::iterator strIter=strVec.begin();
				for(;strIter<strVec.end();strIter++)
				{
						mapIter=map_str.find(*strIter);
						if(mapIter==map_str.end())
						{
								continue;
						}
						*strIter=mapIter->second;
				}

		}
		string res="";
		vector<string>::iterator iterStr=strVec.begin();
		for(;iterStr<strVec.end()-1;iterStr++)
		{
				res=res+*iterStr;
				res=res+" ";
		}
		res=res+*iterStr;
		return res;
}

