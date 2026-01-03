def print_nums(ln,strt):
    if ln.isdigit() == 0 or strt.isdigit() == 0:
        return "invalid input"
    ln=int(ln)
    strt=int(strt)
    l=[]
    for i in range(ln):
        l.append(strt+i)
    return l



ln = input("Enter length: ")
strt = input("Enter start number: ")
print(print_nums(ln,strt))