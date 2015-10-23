#!/usr/bin/python
def seta(a,b):
	return 'l->set(%d,%d);'%(a,b)
def get(a):
	return 'cout<<l->get(%d)<<endl;'%(a)


lista=[seta(10,13),seta(3,17),seta(6,11),seta(10,5),seta(9,10),get(13),seta(2,19),get(2),get(3),seta(5,25),get(8),seta(9,22),seta(5,5),seta(1,30),get(11),seta(9,12),get(7),get(5),get(8),get(9),seta(4,30),seta(9,3),get(9),get(10),get(10),seta(6,14),seta(3,1),get(3),seta(10,11),get(8),seta(2,14),get(1),get(5),get(4),seta(11,4),seta(12,24),seta(5,18),get(13),seta(7,23),get(8),get(12),seta(3,27),seta(2,12),get(5),seta(2,9),seta(13,4),seta(8,18),seta(1,7),get(6),seta(9,29),seta(8,21),get(5),seta(6,30),seta(1,12),get(10),seta(4,15),seta(7,22),seta(11,26),seta(8,17),seta(9,29),get(5),seta(3,4),seta(11,30),get(12),seta(4,29),get(3),get(9),get(6),seta(3,4),get(1),get(10),seta(3,29),seta(10,28),seta(1,20),seta(11,13),get(3),seta(3,12),seta(3,8),seta(10,9),seta(3,26),get(8),get(7),get(5),seta(13,17),seta(2,27),seta(11,15),get(12),seta(9,19),seta(2,15),seta(3,16),get(1),seta(12,17),seta(9,1),seta(6,19),get(4),get(5),get(5),seta(8,1),seta(11,7),seta(5,2),seta(9,28),get(1),seta(2,2),seta(7,4),seta(4,22),seta(7,24),seta(9,26),seta(13,28),seta(11,26)]
for i in lista:
	print i
