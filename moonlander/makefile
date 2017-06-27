###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Falin, CS165
# Author:
#     Jason Reed
# Summary:
#     This is a Moon Lander game. This is an interactive 
#     program with graphics. The user has to land their space
#     pod successfully onto a platform by controlling the 
#	  thrusters using the arrow keys. This program takes in
#	  the real-life applications of inertia and gravity.
# Above and Beyond
#     For this project, I made the lander become disfigured
#     upon impact of the ground. I also made it so that the
#     disfigured lander catches on fire when it crashes.
#     I also changed the color of the ground to orange.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o $(LFLAGS) lander.o velocity.o
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h velocity.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
lander.o: lander.h lander.cpp
	g++ -c lander.cpp

velocity.o: velocity.h velocity.cpp
	g++ -c velocity.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
