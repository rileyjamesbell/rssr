#!/bin/python3

import tkinter as tk,fileinput,re

root= tk.Tk()
root.title("tkread")
root.geometry('600x300')

l=tk.Label(root,text="test",font=("",50))
l.pack()

for line in fileinput.input():
	try:
		l.config(text=re.sub(r'(\x9B|\x1B\[)[0-?]*[ -\/]*[@-~]',"",line))
		root.update()
	except:exit()
