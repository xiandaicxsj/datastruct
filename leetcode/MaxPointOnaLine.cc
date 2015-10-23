#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct Point{
	int x;
	int y;
	Point():x(0),y(0)
	{
	}
	Point(int a,int b):x(a),y(b)
	{

	}
};
class Solution
{
		public:
				int maxPoints(vector<Point> &points)
				{
					int maxLine=0;
					if(points.size()==0)
						return 0;
					int pointSize=points.size();
					map<double,int> slopeCount;
					map<double,int>::iterator sIter;
					double slope=0.0;	
					int i=0;		
					int j=0;
					int dup=0;
					int z=0;
					int max=0;
					for(i=0;i<pointSize;i++)
					{
							
							slopeCount.clear();
							dup=0;
							z=0;
							for(j=i+1;j<pointSize;j++)
							{
									if((points[i].x==points[j].x)&&points[i].y==points[j].y)
									{
											dup++;
											continue;
									}
									if((points[i].x==points[j].x)&&points[i].y!=points[j].y)
									{
											z++;
											continue;
									}
									slope=float(points[j].y-points[i].y)/float(points[j].x-points[i].x);
									sIter=slopeCount.find(slope);
									cout<<slope<<endl;
									if(sIter!=slopeCount.end())
									{
											sIter->second++;
									}
									slopeCount.insert(pair<double ,int>(slope,1));
							}
							sIter=slopeCount.begin();
							if (z+dup>max)
									max=z+dup+1;
							cout<<"dup"<<dup<<endl;
							cout<<"z"<<z<<endl;
							for(;sIter!=slopeCount.end();sIter++)
							{
									if(sIter->second+dup+1>max)
									{
											cout<<max<<endl;
											max=sIter->second+dup+1;
									}
							}
							cout<<max;
							cout<<"DDD"<<endl;
					}
					return max;
				}
};
int main()
{
	vector<Point> p;
	p.push_back(Point(84,250));
	p.push_back(Point(0,0));
	p.push_back(Point(1,0));
	p.push_back(Point(0,-70));
	p.push_back(Point(0,-70));
	p.push_back(Point(1,-1));
	p.push_back(Point(21,10));
	p.push_back(Point(42,90));
	p.push_back(Point(-42,-230));
	Solution s;
	cout<<s.maxPoints(p);
	return 0;
}
