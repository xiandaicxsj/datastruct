#include<iostream>
#include<vector>
using namespace std;
#define MAX 26
struct node
{
		int v;
		bool w;
		node *next[MAX];
};
node *GetNode()
{
		node *tmp=new node();
		for(int i=0;i<MAX;i++)
			tmp->next[i]=NULL;
		tmp->w=false;
		tmp->v=0;
		return tmp;
}
void InsertTire(const char* a,int index,int len,node *head)
{	
		if(!head->next[a[index]-'a'])
				head->next[a[index]-'a']=GetNode();
		if(index==len)
		{
				head->w=true;
				head->v++;
				return ;
		}
		head->v++;
		InsertTire(a,index+1,len,head->next[a[index]-'a']);
}
void FindWord(node *head,vector<char>&s)
{
		for(int i=0;i<MAX;i++)
		{
				if(head->next[i])
				{
						s.push_back('a'+i);
						FindWord(head->next[i],s);
						s.pop_back();
				}
		}
		if(head->w)
		{
			vector<char>::iterator iter=s.begin();
			for(;iter<s.end();iter++)
			{
					cout<<*iter;
			}
			cout<<endl;
			return ;
		}
}
int Pipei(node *head,const char *str,int index,int length)
{
		if(index==length)
			return head->v;
		if(!head->next[str[index]-'a'])
		{
				return 0;
		}
		return Pipei(head->next[str[index]-'a'],str,index+1,length);
}
int main()
{
	node *head=GetNode();
	int i=0;
	int n;
	cin>>n;
	string str;
	for(;i<n;i++)
	{
		cin>>str;
		InsertTire(str.c_str(),0,str.length(),head);
	}
	/*int m;
	cin>>m;
	i=0;
	while(i<m)
	{

	}*/
	int m;
	cin>>m;
	i=0;
	while(i<m)
	{
			cin>>str;
			cout<<Pipei(head,str.c_str(),0,str.length());
	}
//	vector<char> strC;
//	FindWord(head,strC);
	return 0;
}
