def fizzbuzz(n):
    if n.isdigit() == 0:
        return "invalid input"
    n=int(n)
    if n % 15 ==0:
        return "FizzBuzz"
    elif n % 3 == 0:
        return "Fizz"
    elif n % 5 == 0:
        return "Buzz"



n = input("Enter a number: ")
print(fizzbuzz(n))