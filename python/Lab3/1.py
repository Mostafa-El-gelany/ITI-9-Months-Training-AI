l=[]
for i in range(5):
    a=input("enter a number:")
    if a.isdigit():
        l.append(int(a))
    else:
        print("invalid input, please enter a number")
l=sorted(l)
reversed_l=sorted(l,reverse=True)
print("The sorted numbers are:", l)
print("The reversed sorted numbers are:", reversed_l)
