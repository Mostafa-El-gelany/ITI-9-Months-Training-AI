import tabulate
import emoji
import os
import msvcrt
import registration
import login
while 1:
    os.system("cls")
    print("[1] registration "+emoji.emojize(':grinning_face_with_big_eyes:'))
    print("[2] login "+emoji.emojize(':winking_face:'))
    print("[3] exit "+emoji.emojize(':red_circle:'))
    choice = input("enter your choice: ")
    if choice == '1':
        os.system("cls")
        registration.registration()
    elif choice == '2':
        os.system("cls")
        login.login()
    elif choice == '3':
        break
    else:
        print("invalid choice")
        print("press any key to continue...")
        msvcrt.getch()
