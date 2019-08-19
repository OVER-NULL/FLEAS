import tkinter as tk
import menu
import json

pd=json.loads(open("pattern_design.txt","r").read()) #Pattern,Font etc
    
    
#Illustration attempt ,(No real build according to plan)

fleas="""
 ______ _
|  ____| |
| |__  | | ___  __ _ ___
|  __| | |/ _ \/ _` / __|
| |    | |  __/ (_| \__ \ 
|_|    |_|\___|\__,_|___/"""

root = tk.Tk()

root.title("Flea py Template")

root.geometry("900x675") # the size of the app to be X:Y
root.resizable(0, 0) #Don't allow resizing in the x or y direction
root["background"]=pd["Color1"]
root.label=tk.Label(root, text= fleas, font= (pd["Font"], 26), fg= pd["Color2"], bg = root["background"] , justify=tk.LEFT).place(relx=0.5, rely=0.15, anchor=tk.CENTER)

def callback():
    root.destroy()
    menu.menu_screen()

b = tk.Button(root, text="Press Here To Continous",font= (pd["Font"], 40),bg=root["background"], command=callback).place(relx=0.5, rely=0.8, anchor=tk.CENTER)

root.mainloop()


