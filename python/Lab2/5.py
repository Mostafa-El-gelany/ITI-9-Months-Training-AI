def longest_apha_order(string):
    ret =""
    for i in range(len(string)):
        temp=[string[i]]
        j=i+1
        while j<len(string) and string[j]>=string[j-1]:
            temp.append(string[j])
            j+=1
        if len(temp)>len(ret):
            ret=temp
    return ''.join(ret)

s = input("Enter a string: ")
print(longest_apha_order(s))
