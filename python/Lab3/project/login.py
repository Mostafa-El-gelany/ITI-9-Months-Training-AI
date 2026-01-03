from login_funcs import *
from useful_funcs import *
import msvcrt
from getpass import getpass
import login_form
import emoji
def login():
    email=email_registration()
    if email==0:
        return
    
    password = getpass("Enter password: "+emoji.emojize(':locked_with_key:')+" ")
    
    if find(email,password):
        login_user(email)
        login_form.form()
    else:
        print("Invalid email or password."+emoji.emojize(':cross_mark:'))
    
    print("Press any key to continue..."+emoji.emojize(':keyboard:'))
    msvcrt.getch()
