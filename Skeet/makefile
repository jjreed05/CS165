###############################################################
# Program:
#     Project 09, Skeet
#     Brother Falin, CS165
# Author:
#     Jason Reed
# Summary:
#     This is my final code for the Skeet game. This code allows
#     the user to take control of the left arrow, right arrow, 
#     and the space key. The program randomly spawns a random
#     bird. The user has to shoot down the generated birds 
#     unless it the sacred bird (they get docked points for
#     shooting this bird). 
# Above and Beyond
#     I added an extra bird to the game called the Super 
#     Tough Bird. This is an aircraft that requires 4 hits
#     to take down. The user is awarded 6 points (all or 
#     nothing) if they successfully shoot down this aircraft.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o flyingObject.o bird.o bullet.o velocity.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o flyingObject.o bird.o bullet.o velocity.o $(LFLAGS) 

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h bird.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp 
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
flyingObject.o: flyingObject.h flyingObject.cpp
	g++ -c flyingObject.cpp

bird.o: bird.h bird.cpp 
	g++ -c bird.cpp

bullet.o: bullet.h bullet.cpp 
	g++ -c bullet.cpp

velocity.o: velocity.h velocity.cpp
	g++ -c velocity.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
