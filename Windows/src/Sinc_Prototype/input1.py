import tkinter as tk
from tkinter import messagebox
import os


def username():
    #register_screen =

    sign_in = tk.Toplevel()
    global input_username
    global string
    input_username = tk.StringVar()
    sign_in.label = tk.Label(sign_in, text="Log In", font=("Courier New", 26), justify=tk.LEFT).place(relx=0.5,
                                                                                                            rely=0.15,
                                                                                                            anchor=tk.CENTER)
    sign_in.geometry("300x375")  # set the configuration of GUI window
    sign_in.resizable(0, 0)
    #set username label
    username1 = tk.Label(sign_in, text = "User Name", font= ("Courier New", 10)).place(relx=0.2, rely=0.5, anchor=tk.CENTER)
    username_login = tk.Entry(sign_in, textvariable = input_username).place(relx=0.7, rely=0.5, anchor=tk.CENTER)
    sign_in.focus()
    string = input_username.get()
    def recall():
        username()

    def verify_log_in():
        signed = "H" #set the login username
        #print(f"{input_username.get()}")
        name = input_username.get()  #get user name input
        if name == signed:   #compare the input username and the registered account
            messagebox.showinfo("Result", "Log in Sucessfully")   #if true, return sucessfully
            sign_in.destroy()       #destroy the pop up


        else:
            messagebox.showerror("Error", "Please Login Again" )  #pop up error when wrong
            sign_in.destroy()  #destroy the log in
            username()





    signIn= tk.Button(sign_in, text = "Log In", font= ("Courier New", 14), command =verify_log_in).place(relx=0.3, rely=0.8, anchor=tk.CENTER)   #sign in button
    def terminate():     # to quit the log in screen
        sign_in.destroy()


    terminal = tk.Button(sign_in, text = "Quit",  font= ("Courier New", 14), command =terminate).place(relx=0.7, rely=0.8, anchor=tk.CENTER)  #terminate button


def Instruction():

     Instruk = tk.Toplevel()
     Instruk.geometry("900x675")  # set the configuration of GUI window
     Instruk.resizable(0, 0)
     cwd = os.getcwd()  # Get the current working directory (cwd)
     files = os.listdir(cwd)  # Get all the files in that directory
     print("Files in %r: %s" % (cwd, files))

     file= open("D:\\Program Files (x86)\\untitled\\instruk", "r") #fix your directory
     content = file.read()
     Instruk.label = tk.Label(Instruk, text=content, font=("Courier New", 10), justify=tk.LEFT).place(relx=0.5,
                                                                                                             rely=0.15,
                                                                                                             anchor=tk.CENTER)
     def callback():
         Instruk.destroy()

     Button1 = tk.Button(Instruk, text="Close", font=("Courier New", 14), command=callback).place(relx=0.5, rely=0.9,
                                                                                                    anchor=tk.CENTER)  # log in button



def login_screen():

    loginscreen = tk.Tk()
    loginscreen.label = tk.Label(loginscreen, text = "Menu", font= ("Courier New", 26), justify=tk.LEFT).place(relx=0.5, rely=0.15, anchor=tk.CENTER)
    loginscreen.geometry("900x675")  # set the configuration of GUI window
    loginscreen.resizable(0, 0)
    loginscreen.title("Account Login")  # set the title of GUI window
    loginscreen["background"]="#5d0963"

    def recall():  #call to another definition
        username()
    def CallInstruction():
        Instruction()


    Button1 = tk.Button(loginscreen, text = "Login",font= ("Courier New", 14), command = recall).place(relx=0.5, rely=0.5, anchor=tk.CENTER)   #log in button
    Button2 = tk.Button(loginscreen, text="Instruction", font= ("Courier New", 14), command = CallInstruction).place(relx=0.5, rely=0.6, anchor=tk.CENTER)  #instruction button



    loginscreen.mainloop()





























