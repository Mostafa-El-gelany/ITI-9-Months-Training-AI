n=input("enter a number: ")
l=[]
if n.isdigit():
    n=int(n)
    for i in range(1,n+1):
        temp=[]
        for j in range(1,i+1):
            temp.append(i*j)
        l.append(temp)
    for i in l:
        print(i)
else:
    print("invalid input")
