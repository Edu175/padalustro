from os import system
it=100
for _ in range(it):
	system("./c<pre>in")
	system("./a<in>o")
	system("./b<in>o2")
	x=open("o","r").read().strip().split()
	y=open("o2","r").read().strip().split()
	if(x!=y):
		print("FAILED!!!")
		print("greedy:",x,"bf:",y)
		exit(0)
	print("ok",_+1)
