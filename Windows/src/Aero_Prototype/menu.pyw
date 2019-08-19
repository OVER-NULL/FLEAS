import tkinter as tk
import tkinter.scrolledtext as crolled
import menu #lol? but essential
import json

pd=json.loads(open("pattern_design.txt","r").read()) #Pattern,Font etc


def Instruction():
    Instruk = tk.Tk()
    Instruk.geometry("900x675")  # set the configuration of GUI window
    Instruk.resizable(0, 500)

     
    try:
        Instruk.st=crolled.ScrolledText(Instruk, height=20,width=70,font=(pd["Font"], 14),bg=pd["Color1"],fg=pd["Color2"])
        
        Instruk.st.insert( tk.INSERT ,open("instructions.txt", "r").read() )

        Instruk.st.place(relx=0.5, rely=0.45, anchor=tk.CENTER)
        
    except:
        print("Instructions Reading Problem 404 Ask Aero")
        
    Button1 = tk.Button(Instruk, text="Close", font=(pd["Font"], 14), command=lambda:(Instruk.destroy(),menu_screen())).place(relx=0.5, rely=0.9, anchor=tk.CENTER)  # log in button



def menu_screen():

    loginscreen = tk.Tk()
    loginscreen.label = tk.Label(loginscreen, text = "Menu", font= (pd["Font"], 26), justify=tk.LEFT).place(relx=0.5, rely=0.15, anchor=tk.CENTER)
    loginscreen.geometry("900x675")  # set the configuration of GUI window
    loginscreen.resizable(0, 0)
    loginscreen.title("Fleas Menu")  # set the title of GUI window
    loginscreen["background"]=pd["Color1"]

    Button2 = tk.Button(loginscreen, text="Instruction", font= (pd["Font"], 14), command = lambda:(loginscreen.destroy(),Instruction()) ).place(relx=0.5, rely=0.6, anchor=tk.CENTER)  #instruction button


    #loginscreen.mainloop()





























