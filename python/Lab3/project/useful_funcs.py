import bcrypt

def fname_check(fname):
    return fname.isalpha()


def lname_check(lname):
    return lname.isalpha()


def email_check(email):
    return email.endswith("@gmail.com")


def password_check(password):
    return len(password)>=8

def confirm_password(password, cpassword):
    return password == cpassword

def phone_check(phone):
    return phone.isdigit() and len(phone) == 11 and phone.startswith("01") and phone[2] in "0125"

def email_exists(email):
    file =open("users.txt", "r")
    for line in file:
        stored_email = line.strip().split(",")[3]
        if stored_email == email:
            return True
    return False

def hashed_password(password):
    return bcrypt.hashpw(password.encode(), bcrypt.gensalt()).decode()

def get_id(email):
    file =open("users.txt", "r")
    for line in file:
        stored_email, stored_id = line.strip().split(",")[3], line.strip().split(",")[0]
        if stored_email == email:
            return stored_id
    return 0

def login_user(email):
    id = get_id(email)
    file=open("current_user.txt", "w")
    file.write(id)
    file.close()



def validate_date(str_date):
    l=str_date.strip().split('/')
    if len(l) !=3:
        return 0
    
    year,month,day=l[2],l[1],l[0]
    
    year=int(year)
    month=int(month)
    day=int(day)
    
    if year<2026:
        return 0
    
    if month<1 or month >12 :
        return 0
    
    if day <1 or day > 31 :
        return 0
    
    return 1

def compare_date(start_date,end_date):
    syear,smonth,sday=start_date.split('/')
    eyear,emonth,eday=end_date.split('/')
    
    syear=int(syear)
    smonth=int(smonth)
    sday=int(sday)
    
    eyear=int(eyear)
    emonth=int(emonth)
    eday=int(eday)
    
    if eyear<syear:
        return 0
    if emonth<smonth:
        return 0
    if eday<sday:
        return 0
    return 1

def get_current_user():
    file=open('current_user.txt','r')
    user_id = file.read()
    file.close()
    return user_id

def get_project_id():
    file=open('project_id.txt','r')
    id=int(file.read())
    file.close()
    return id

def increase_project_id():
    file=open('project_id.txt','r')
    id=int(file.read())
    file.close()
    file=open('project_id.txt','w')
    file.write(str(id+1))
    file.close()

def store_project(user_id, project_id, title,details,target,start_date,end_date):
    file=open('projects.txt', 'a')
    file.write(f"{user_id},{project_id},{title},{details},{target},{start_date},{end_date}\n")
    file.close()