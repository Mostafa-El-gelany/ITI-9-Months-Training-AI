total=0
cnt=0

while 1:
    number = input("Enter a number: ")
    if number == 'done':
        if cnt == 0:
            print("No numbers were entered.")
            break
        print(f"Total: {total} \nCount: {cnt} \nAverage: {total/cnt}")
        break
    if number.isdigit() == 0:
        print("Invalid input")
        input("Press any key to continue...")
    else:
        number=int(number)
        total+=number
        cnt+=1