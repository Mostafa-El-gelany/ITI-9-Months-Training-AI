import msvcrt
import os
a = 1
while 1:
    os.system('cls')
    print("new\ndisplay\nexit\n")
    print("enter (n,d,e)\n")
    key = msvcrt.getch()
    if key == b'n' or key == b'N':
        print("new item was added:\n")
    elif key == b'd' or key == b'D':
        print("display items was selected:\n")
    elif key == b'e' or key == b'E':
        print("exit was selected:\n")
        break
    else:
        print("invalid key was pressed:\n")
    print('press anykey to continue...')
    key = msvcrt.getch()