import random
words=['mostafa','ahmed','noha','emad','raafat','sharaf','halawa','marawan']
idx=random.randint(0,len(words)-1)
string=words[idx]
name=input("Enter your name: ")
for i in range(7):
    c=input("Enter a character: ")
    if c.isalpha() and len(c)==1:
        for i in string:
            if i==c:
                print(i, end='')
            else:
                print('_', end='')

    else:
        print("Invalid input")
        continue
guess=input("\nGuess the word: ")
if guess==string:
    print("what a genius")
else:
    print(f"You lose! The word is {string}")