from pathlib import Path
from datetime import date
def input_lift():

    f = open("lifts.txt", "a")
    lift = input("Enter lift name: ")
    weight = input("Enter weight: ")
    reps = input("Enter reps: ")
    date_today = str(date.today()) + "\n"
    one_rm = str(float(weight) / (1.0278 - (0.0278 * float(reps))))
    weight = str(weight)
    reps = str(reps)
    one_rm += "\n\n\n\n\n"
    lift_txt = "Lift: " + lift + "\n"
    reps_weight_txt = weight + " for " + reps + " reps.\n"
    one_rm_txt = "1RM for " + lift + ": " + one_rm
    answer = input("Enter 'n' to not enter data: ")
    if answer == "n":
        quit()

    f.write(date_today)
    f.write(lift_txt)
    f.write(reps_weight_txt)
    f.write(one_rm_txt)
    f.close()

def login():
    f = open("login.txt", "r")
    array = []
    array = f.readlines()
    res = []
    for sub in array:
        res.append(sub.replace("\n", ""))

    uname = res[0]
    pword = res[1]

    while(True):
        input1 = input("Please enter username: ")
        if input1 == uname:
            break
    while(True):
        input2 = input("Please enter password: ")
        if input2 == pword:
            break

    print("\nYou are now logged in!")

def get_login():
    user_name = input("Please enter your new username: ")
    pword = input("Please enter your new password: ")
    f = open("login.txt", "w")
    user_name += '\n'
    f.write(user_name)
    f.close()
    f = open("login.txt", "a")
    f.write(pword)
    f.close()

    print("Now please login...\n\n\n")

def main():
    login_file = Path("C:/swe1/termproject/login.txt")
    if Path.exists(login_file):
        login()
    else:
        get_login()
        login()


    input_lift()


main()