'''
import sys

st =""
print(sys.getsizeof(st))  # Size of empty string

st="1235"
print(int(st))

#st="564k"
#print(int(st))  
print("hio" and "huigy")

st="asdfghjk"
'''


import json
import tabulate
print(tabulate.tabulate([["Name", "Age"], ["Alice", 30], ["Bob", 25]], headers="firstrow"))


#what is decorator in python?  --> @
'''
2- 
'''

s='[1,2,3 ,4]'

l=list(s.strip('[]').split(','))
print(l)  # Output: [1, 2, 3, 4]
