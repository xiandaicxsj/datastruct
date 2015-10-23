#include <stdio.h>
#include <string.h>

int main()
{
	    int array[36];
			    char output[100][100];
					    int info[100] = {1};
							    char input[100];
									    int i,m,length,n = 0;
													    while(scanf("%s",input)!=EOF)
																    {
																			        length = strlen(input);
																							        for(i = 0; i < 36; i++)
																												            array[i] = 0;
																											        for(i = 0;i < length; i++)
																																        {
																																					            if(!(input[i]>='0'&&input[i]<='9'||input[i]>='a'&&input[i]<='z'))
																																												            {
																																																			                info[n] = 0;
																																																											                break;
																																																																			            }
																																											            else if(input[i]>='0'&&input[i]<='9')
																																																		            {
																																																									                array[input[i]-'0']++;
																																																																	            }
																																																	            else
																																																								                array[input[i]-'a'+10]++;
																																																							        }
																															        m = 0;
																																			        while(m<length)
																																								        {
																																													            for(i = 0; i < 10; i++)
																																																				            {
																																																											                if(array[i] != 0)
																																																																				                {
																																																																													                    output[n][m]=(char)('0'+i);
																																																																																							                    array[i]--;
																																																																																																	                    m++;
																																																																																																											                }
																																																																			            }
																																																			            for(i = 10;i < 36; i++)
																																																										            {
																																																																	                if(array[i] != 0)
																																																																										                {
																																																																																			                    output[n][m]=(char)('a'+i-10);
																																																																																													                    array[i]--;
																																																																																																							                    m++;
																																																																																																																	                }
																																																																									            }
																																																									        }
																																							        n++;
																																											    }
															    for(i = 0; i < n; i++)
																		    {
																					        if(info[i])
																										            printf("%s\n",output[i]);
																									        else 
																														            printf("<invalid input string>\n");
																													    }
}
