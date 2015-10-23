#!/usr/bin/python
#coding=utf-8
#我觉得这个是美问题的了，但是无法ac
def find_p(path):
		pathList=path.split('/')
		print pathList
		while '' in pathList:
				pathList.remove('')
		while '.' in pathList:
				pathList.remove('.')
		pathLen=len(pathList)
		retList=[]
		i=0
		while i<pathLen:
			tmp=pathList[i]
			if tmp=='..':
					if len(retList)==0:
							i=i+1
							continue
					del retList[len(retList)-1]
					i=i+1
					continue
			retList.append(tmp)
			i=i+1
		return '/'+'/'.join(retList)

print find_p("/sdsdfs/../c")
print find_p('home//foo')
print find_p('/home/')
print find_p('/a/./b/../../c')
print find_p('/../../')
print find_p('/')
