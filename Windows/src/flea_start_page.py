import tkinter as tk

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
root["background"]="#5d0963"
root.label=tk.Label(root, text= fleas, font= ("Courier New", 26), fg= "white", bg = root["background"] , justify=tk.LEFT).place(relx=0.5, rely=0.15, anchor=tk.CENTER)

def callback():
    print ("click!")

b = tk.Button(root, text="Start",font= ("Courier New", 40),bg="Green", command=callback).place(relx=0.5, rely=0.8, anchor=tk.CENTER)

root.mainloop()
