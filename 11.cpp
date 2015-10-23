#include<iostream>
#include<vector>
using namespace std;
int charCount[36];
int main()
{
	
	vector<string> resVec;
	string str1;
	string str;
	while(!cin.eof())
	{
		cin>>str;
		if(str1==str)
			break;
		str1=str;
		if(str.length()==0)
			break;
		int i=0;
		int wCharFlag=0;
		int strLen=str.length();
		string res;
		for(i=0;i<36;i++)
			charCount[i]=0;
		for(i=0;i<strLen;i++)
		{
				if(str[i]>='0'&&str[i]<='9')
				{
					charCount[str[i]-'0']++;
					continue;
				}
				if(str[i]>='a'&&str[i]<='z')
				{
					charCount[str[i]-'a'+10]++;
					continue;
				}
				wCharFlag=1;
		}
		if(wCharFlag)
		{
				res="<invalid input string>";
		}
		else
		{
				int charIndex;
				int allDone=0;
				while(allDone==0)
				{
						allDone=1;
						for(charIndex=0;charIndex<36;charIndex++)
						{
								if(charCount[charIndex]!=0)
								{
									char tmp;
									allDone=0;
									if(charIndex<=9)
										tmp='0'+charIndex;
									else
										tmp='a'+charIndex-10;
									res=res+tmp;
									charCount[charIndex]--;
									continue;
								}
						}
				}						
		}
		resVec.push_back(res);
	}
	vector<string>::iterator str_iter=resVec.begin();
	for(;str_iter<resVec.end();str_iter++)
			cout<<*str_iter<<endl;
}
