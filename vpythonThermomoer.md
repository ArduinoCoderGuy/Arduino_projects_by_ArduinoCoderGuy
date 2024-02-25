# for the lessons from Paul McWhorter, my version of a thermomoter, ready to get data from Arduino

from vpython import *
from time import *
import numpy as np 
box1 = box(len = 5,width = .01,height = .05,pos = vector (0,-2.5,0), color = color.blue)
box1 = box(len = 5,width = .01,height = .05,pos = vector (0,-2,0), color = color.blue)
box1 = box(len = 5,width = .01,height = .05,pos = vector (0,-1.5,0), color = color.cyan)
box1 = box(len = 5,width = .01,height = .05,pos = vector (0,-1,0), color = color.green)
box1 = box(len = 5,width = .01,height = .05,pos = vector (0,-.5,0), color = color.green)
box1 = box(len = 5,width = .01,height = .05,pos = vector (0,0,0), color = color.green)
box1 = box(len = 5,width = .01,height = .05,pos = vector (0,.5,0), color = color.yellow)
box1 = box(len = 5,width = .01,height = .05,pos = vector (0,1,0), color = color.yellow)
box1 = box(len = 5,width = .01,height = .05,pos = vector (0,1.5,0), color = color.magenta)
box1 = box(len = 5,width = .01,height = .05,pos = vector (0,2,0), color = color.red)
sphere1 = sphere(pos = vector(0,-3,0),radius = 0.5, color=color.red, opacity=1)
sphere2 = sphere(pos = vector(0,-3,0), radius = .3, color = color.red)
cylinder1 = cylinder(pos = vector(0,-3,0),axis = vector (0,90,0), radius = .3, length = 5, color = color.red)

myLength = 5
sphere2xPos = -3
while True:
    for myLength in np.linspace (.1,5,1000):
        rate(250)
        cylinder1.axis = vector (0,myLength,0)
        sphere2.pos = vector (0,myLength-3,0)
    for myLength in np.linspace (5,0.1,1000):
        rate(250)
        cylinder1.axis = vector (0,myLength,0)
        sphere2.pos = vector (0,myLength-3,0)
