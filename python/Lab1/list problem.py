l=[]
print("enter 5 numbers")
for i in range(5):
    n=input()
    if n.isdigit():
        l.append(int(n))

sorted_l=sorted(l)
sorted_l2=sorted(l, reverse=True)
print(sorted_l)
print(sorted_l2)
