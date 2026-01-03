from useful_funcs import *
import bcrypt
import emoji
def email_registration():
    for i in range(3):
        email=input("Enter email: "+emoji.emojize(':e-mail:')+" ")
        email=email.strip()
        if  email_check(email):
            return email
        else:
            print("Invalid email."+emoji.emojize(':cross_mark:'))
    return 0

def find(email,password):
    file =open("users.txt", "r")
    for line in file:
        stored_email, stored_password = line.strip().split(",")[3], line.strip().split(",")[4]
        if stored_email == email and bcrypt.checkpw(password.encode(), stored_password.encode()):
            return True
    return False

