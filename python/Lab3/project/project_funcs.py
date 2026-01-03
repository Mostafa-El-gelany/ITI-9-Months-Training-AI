from useful_funcs import *
import msvcrt
import tabulate
def create_project(project_id=get_project_id(),state=-1):
    title=input('enter title. ')
    title=title.strip()
    if len(title)==0:
        return
    
    details=input('enter details. ')
    
    target=input('enter total target. ')
    if target.isdigit()==0:
        return
    
    start_date=input('enter start date in this format.\nday/month/year \nexample 3/5/2025\n')
    
    if validate_date(start_date)==0:
        return 
    
    end_date=input('enter last date.\n')
    
    if validate_date(end_date)==0:
        print('wrong end date.')
        a=msvcrt.getch()
        return
    
    if compare_date(start_date,end_date)==0:
        print('end date must be after start date.')
        a=msvcrt.getch()
        return
    if state==-1:
        project_id = get_project_id()
    user_id = get_current_user()
    store_project(user_id, project_id, title,details,target,start_date,end_date)
    increase_project_id()
    print('project created successfully.')

def view_projects():
    file=open('current_user.txt','r')
    user_id=file.read()
    file.close()
    file=open('projects.txt','r')
    for line in file:
        project=line.split(',')
        if project[0]==user_id:
            table = [
                ["User ID", project[0]],
                ["Project ID", project[1]],
                ["Title", project[2]],
                ["Details", project[3]],
                ["Target", project[4]],
                ["Start Date", project[5]],
                ["End Date", project[6]]
            ]
            print(tabulate.tabulate(table))
            print('---------------------')
    file.close()
    print("press any key to continue...")
    msvcrt.getch()


def edit_project():
    view_projects()
    project_id=input('enter the project id you want to edit. ')
    project_id=project_id.strip()
    d=delete_project0(project_id)
    if d:
        create_project(project_id=project_id,state=0)
    else:
        print('project id not found.')
        print("press any key to continue...")
        msvcrt.getch()


def delete_project0(project_id):
    flag=0
    file=open('projects.txt','r')
    lines=file.readlines()
    file.close()
    file=open('projects.txt','w')
    
    for line in lines:
        project=line.split(',')
        if project[1]==project_id and project[0]==get_current_user():
            flag=1
        else:
            file.write(line)
    file.close()
    return flag

def delete_project():
    project_id=input('enter the project id you want to delete. ')
    if project_id.isdigit()==0:
        return
    d=delete_project0(project_id)
    if d:
        print('project deleted successfully.')
    else:
        print('project id not found.')
    print("press any key to continue...")
    msvcrt.getch()
