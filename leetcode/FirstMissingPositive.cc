#include<iotream>
using namespace std;
class Solution
{
		public://排序
				int firstMissingPositive(int A[],int n)
				{
						if(n<0)
							return 1;
						int pos;
						for(pos=0;pos<n;pos++)
						{
								if(A[pos]>0&&A[pos]!=pos+1&&A[pos]<n&&A[A[pos]-1]!=A[pos])
								{//最后的条件是为了防止出现都个重复的情况作的
										tmp=A[A[pos]-1];
										A[A[pos]-1]=A[pos];
										A[pos]=tmp;
								}
								else pos++;
						}
						for(itn i=0;i<n;i++)
							if(A[i]!=i+1)
							{
									return i+1;
							}
				}

}
