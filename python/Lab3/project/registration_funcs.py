from useful_funcs import *
from getpass import getpass
def fname_registration():
    for i in range(3):
        fname=input("Enter first name: ")
        fname=fname.strip()
        if fname_check(fname):
            return fname
        else:
            print("Invalid first name.")

    print("Invalid first name")
    return 0

def lname_registration():
    for i in range(3):
        lname=input("Enter last name: ")
        lname=lname.strip()
        if lname_check(lname):
            return lname
        else:
            print("Invalid last name.")

    return 0

def phone_registration():
    for i in range(3):
        phone=input("Enter phone number: ")
        phone=phone.strip()
        if phone_check(phone):
            return phone
        else:
            print("Invalid phone number.")
    
    return 0

def email_registration():
    for i in range(3):
        email=input("Enter email: ")
        email=email.strip()
        if  email_check(email):
            if email_exists(email):
                print("Email already exists.")
            else:
                return email
        else:
            print("Invalid email.")
    return 0

def password_registration():
    for i in range(3):
        password = getpass("Enter password: ")
        if password_check(password):
            return password
        else:
            print("password is too short.")
    return 0

def cpassword_registration(password):
    for i in range(3):
        cpassword=getpass("Confirm password: ")
        if confirm_password(password,cpassword):
            return cpassword
        else:
            print("Password not matched.")
    return 0


def get_id():
    file=open("user_id.txt","r")
    id=file.read()
    file.close()
    id=int(id)+1
    file=open("user_id.txt","w")
    file.write(str(id))
    file.close()
    return id

def store_user(id,fname,lname,email,password,phone):
    file=open("users.txt","a")
    file.write(f"{id},{fname},{lname},{email},{hashed_password(password)},{phone}\n")
    file.close()