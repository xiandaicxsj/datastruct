#include<iostream>
#include<string>
#include<vector>
using namespace std;
char baseChar='a';
int root=0;
int emptyIndex=1;
vector<char> c_vec;
struct treeNode
{
	public:
		treeNode(int _childIndex=-1,int _value=-1,int _flag=-1):value(_value),childIndex(_childIndex){
		flag=_flag;	
		}
		int value;
		int childIndex;
		int flag;
};
treeNode tireTree[3000][26];
void insert(string str1)
{
	char u=0;
	int preNode=0;
	int len=str1.length();
		for(int i=0;i<len;i++)
		{
				if(tireTree[u][str1[i]-'a'].flag==-1)
				{
						tireTree[u][str1[i]-'a'].childIndex=emptyIndex;
						tireTree[u][str1[i]-'a'].flag=0;
					//	preNode=u;
						emptyIndex++;
				}
				preNode=u;
				u=tireTree[u][str1[i]-'a'].childIndex;
				if(i==len-1)
				{
						tireTree[preNode][str1[i]-'a'].value=1;//标示一个单词的结尾
				}
		}
}
void ShowTireTree(int index)
{
		for(int i=0;i<26;i++)
		{
				if(tireTree[index][i].flag!=-1)
				{
						c_vec.push_back(char(i+'a'));
						if(tireTree[index][i].value==1)
						{
							//
							vector<char>::iterator i_ter=c_vec.begin();
							for(;i_ter!=c_vec.end();i_ter++)
							{
									cout<<*i_ter;
							}
							cout<<endl;
							//output
							c_vec.pop_back();
							continue;
						}
						ShowTireTree(tireTree[index][i].childIndex);
						c_vec.pop_back();
				}
		}

				
}
/*int Spilt(string word,int index,int begin,int end)
{
			int sum=0;
			while(begin<=end)
			{
					if (tireTree[index][word[begin]-'a'].value!=1)
					{
						begin++;
						index=tireTree[index][word[begin]-'a'].childIndex;
						continue;
					}
					begin++;
					sum+=Spilt(word,index,begin,end);
			}
			return sum;

}*/
int WordExits(string word,int begin,int end)
{
		int index=0;
		while(begin<=end)
		{
				if(begin==end&&tireTree[index][word[begin]-'a'].flag==0&&tireTree[index][word[begin]-'a'].value==1)
				{
						return 1;

				}
				if(tireTree[index][word[begin]-'a'].flag==0)
				{
					index=tireTree[index][word[begin]-'a'].childIndex;	
					begin++;
				}
				else
					return 0;
					
		}
		return 0;
}
int RememberWord(string word)
{
		int len=word.length();
		int *sum=new int[len];
		for(int i=0;i<len;i++)
				sum[i]=0;
		sum[len-1]=tireTree[0][word[len-1]-'a'].value==1?1:0;
		for(int i=len-2;i>=0;i--)
		{
				int end=i;
				while(end<=len-1)
				{
					if(WordExits(word,i,end)==1)
					{
							if(end==len-1)
							{
									sum[i]+=1;
							}
							else
								sum[i]+=sum[end+1];
					}
					end++;
				}
		}
		return sum[0];
}
int main()
{
	/*对应的是LA 3982
	insert("a");
	insert("b");
	insert("cd");
	insert("ab");
	cout<<RememberWord("abcd");
	//初始化以及相应的处理
	*/
	return 0;
}


