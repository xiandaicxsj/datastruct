#include<iostream>
#include<vector>
using namespace std;
struct ScanLine{
		float x;
		float y1;
		float y2;
		int flag;//left or right
		ScanLine(float xl=-1,float yl=-1,float yr=-1,int tflag=-1):x(xl),y1(yl),y2(yr),flag(tflag)
		{
		}
};
struct Node
{
	Node(int _l=-1,int _r=-1,int _ml=-1,int _mr=-1,int _cover=0,int _value=0):l(_l),r(_r),ml(_ml),mr(_mr),value(_value),cover(_cover){
	}
	int l;
	int r;
	float ml;
	float mr;
	int cover;
	int value;
};
Node lineTree[2000];
ScanLine scanLines[2000];
float y[2000];
void BuildLineTree(int index,int left,int right)
{
		int mid=(left+right)/2;
		lineTree[index]=Node(left,right,y[left],y[right]);
		if (left+1==right)
			return;
		BuildLineTree(2*index,left,mid);
		BuildLineTree(2*index+1,mid,right);
}
int indexY=0;
int indexS=0;
void Insert(float _y)
{
		y[indexY]=_y;
		indexY++;
}
void  caclute(int index)
{
	if(lineTree[index].cover>0)
	{
			lineTree[index].value=lineTree[index].mr-lineTree[index].ml;
			return ;
	}
	else
	{
			lineTree[index].value=lineTree[2*index].value+lineTree[2*index+1].value;
	}
	return ;
}
void Scan(int index,ScanLine s)
{
		
	if(lineTree[index].ml==s.y1&&lineTree[index].mr==s.y2)
	{
			lineTree[index].cover+=s.flag;
			caclute(index);
			return; 
	}
	if(s.y2<=lineTree[index*2].mr)//y2>y1
		Scan(index*2,s);
	else if(s.y1>=lineTree[index*2+1].ml)
		Scan(index*2+1,s);
	else
	{
			ScanLine tmp=s;
			tmp.y2=lineTree[index*2].mr;
			Scan(index*2,tmp);
			tmp=s;
			tmp.y1=lineTree[index*2+1].ml;
			Scan(index*2,tmp);
	}
	caclute(index);
}
int compareY(const void *a,const void *b)
{
	//Y数组的重复问题
		 if((*(float *)a-*(float *)b)>0)
			{
							return 1;
			}
		 return 0;

}
int compareScanLine(const void *a ,const void *b)
{
		return ((ScanLine *)a)->x-((ScanLine *)b)->x;
}
int main()
{
		int numTang;
		cout<<"Input the num of tangle"<<endl;
		cin>>numTang;
		int sum=0;
		for(int i=0;i<numTang;i++)
		{
				float xl;
				float yl;
				float xr;
				float yr;
				cin>>xl;
				cin>>yl;
				cin>>xr;
				cin>>yr;
				scanLines[indexS]=ScanLine(xl,yl,yr,1);
				indexS++;
				scanLines[indexS]=ScanLine(xr,yl,yr,-1);
				indexS++;
				Insert(yl);
				Insert(yr);
		}
		qsort(y,indexY,sizeof(float),compareY);
		qsort(scanLines,indexS,sizeof(ScanLine),compareScanLine);
		//sort(scanLine3);这里需要对scanLines进行按照x进行排序
		BuildLineTree(1,0,indexY-1);//建立线段树
		Scan(1,scanLines[0]);	
		sum+=lineTree[1].value*(scanLines[1].x-scanLines[0].x);
		for(int i=1;i<indexS-1;i++)
		{
			//Scan(0,scanLines[i]);
			sum+=(scanLines[i+1].x-scanLines[i].x)*lineTree[i].value;//这里实际是更新的前一个的数据
			Scan(1,scanLines[i]);
		}

		return 0;
}
