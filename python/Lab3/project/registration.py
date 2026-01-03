from useful_funcs import *
from registration_funcs import *
import msvcrt
import emoji
def registration():
    fname=fname_registration()
    if fname==0:
        exit()
    
    lname=lname_registration()
    if lname==0:
        exit()
    
    email=email_registration()
    if email==0:
        exit()
    
    password=password_registration()
    if password==0:
        exit()
    
    cpassword=cpassword_registration(password)
    if cpassword==0:
        exit()
    
    phone=phone_registration()
    if phone==0:
        exit()
    
    id=get_id()
    
    store_user(id,fname,lname,email,password,phone)
    
    print("Registration successful."+emoji.emojize(':party_popper:'))
    print("Press any key to continue..."+emoji.emojize(':keyboard:'))
    msvcrt.getch()