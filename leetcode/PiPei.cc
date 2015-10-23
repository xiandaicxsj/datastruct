#include<iostream>
#include<vector>
using namespace std;

int isPiPei(char *a,int al,char *b,int bl)
{
		int aIndex=0;
		int bIndex=0;
		int isFlag=false;
		vector<int> indexA;
		vector<int> indexB;
		while(bIndex<bl)
		{
				if(a[aIndex]==b[bIndex])
				{
					aIndex++;
					bIndex++;
					continue;
				}
				if(isFlag)
				{
					bIndex++;
					continue;
				}
				if(a[aIndex]!='*'&indexA.size()==0)
					return false;
				if(a[aIndex]!='*'&indexA.size()!=0)
				{
						int flag=false;
						while(!flag)
						{
						aIndex=indexA.back();
						indexA.pop_back();
						bIndex=indexB.back();
						bIndex++;
						while(bIndex<bl&&b[bIndex]!=a[aIndex])
							bIndex++;
						if(bIndex!=bl)
						{
								indexA.push_back(aIndex);
								indexB.push_back(bIndex);
								flag=true;
						}
						}
						continue;
				}
				if(a[aIndex]=='*')
				{
						while(a[aIndex]!='*')
							aIndex++;
						while(b[bIndex]!=a[aIndex])
								bIndex++;	
					indexA.push_back(aIndex);	
					indexB.push_back(bIndex);
				}
		}


}
int main()
{
	return 0;
}
