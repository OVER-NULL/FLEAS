import tkinter as tk
from tkinter import messagebox as message


import os, sys



def verify_log_in():
    login_screen.destroy()
    username1  = input_username.get()
    path ="D:/Program Files (x86)/untitled"

    list_of_file = os.listdir(path)
    if username1 in list_of_file:
        file1= open(username1, "r")
        verify = file1.read().splitlines()
        message = tk.message.showinfo("Login", "Sucessfully")








def username():
    #register_screen =

    sign_in = tk.Toplevel()
    global input_username
    input_username = tk.StringVar()

    sign_in.geometry("900x675")  # set the configuration of GUI window
    sign_in.resizable(0, 0)
    #set username label
    username = tk.Label(sign_in, text = "User Name", font= ("Courier New", 14)).place(relx=0.2, rely=0.5, anchor=tk.CENTER)
    username_login = tk.Entry(sign_in, textvariable = input_username).place(relx=0.5, rely=0.5, anchor=tk.CENTER)
    signIn= tk.Button(sign_in, text = "Log In", font= ("Courier New", 14)).place(relx=0.5, rely=0.8, anchor=tk.CENTER)


def login_screen():

    loginscreen = tk.Tk()

    loginscreen.geometry("900x675")  # set the configuration of GUI window
    loginscreen.resizable(0, 0)
    loginscreen.title("Account Login")  # set the title of GUI window
    loginscreen["background"]="#5d0963"

    Button1 = tk.Button(loginscreen, text = "Login",font= ("Courier New", 14), command = username).place(relx=0.5, rely=0.5, anchor=tk.CENTER)
    Button2 = tk.Button(loginscreen, text="Instruction", font= ("Courier New", 14)).place(relx=0.5, rely=0.6, anchor=tk.CENTER)

    loginscreen.mainloop()





























