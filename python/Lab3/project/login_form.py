import os
import project_funcs
import emoji
def form():
    while 1:
        os.system('cls')
        print("This is the login form."+emoji.emojize(':bust_in_silhouette:'))
        print('[1] create a project fund.'+emoji.emojize(':memo:'))
        print('[2] view your projects.'+emoji.emojize(':eyes:'))
        print('[3] edit your project.'+emoji.emojize(':pencil:'))
        print('[4] delete your project.'+emoji.emojize(':wastebasket:'))
        print('[5] logout.'+emoji.emojize(':door:'))
        n=input()
        n=n.strip()
        if n=='1':
            project_funcs.create_project(-1)
        elif n=='2':
            project_funcs.view_projects()
        elif n=='3':
            project_funcs.edit_project()
        elif n=='4':
            project_funcs.delete_project()
        elif n=='5':
            break
        else:
            print("invalid input."+emoji.emojize(':cross_mark:'))