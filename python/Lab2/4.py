def gmail_check(gmail):
    temp="@gmail.com"
    return gmail.endswith(temp)



name = input("Enter your name: ")
if name.isdigit() or name=="" :
    print("invalid Name")
    exit()
gmail=input("Enter your gmail: ")
if not gmail_check(gmail):
    print("invalid Email")
    exit()

print(f"Hello {name},\nyour gmail is {gmail}")
