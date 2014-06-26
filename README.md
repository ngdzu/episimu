episimu
=======

Epidemic Simulator - CS410 class project, Spring 2012. Professor Marc Pomplun


This application was written by Dzu Nguyen. Some of the code and UI design was done by Edward Saad.


The program simulates how a disease is transmitted within a community where people travel around the street. There is a graphical presentation of people and houses. After getting the disease, the people will go through disease stages:

- healthy (represented in white color): The resident has never gotten the disease before 
- incubating (yellow): The resident catched the disease but has not ben contagious. He can't pass the disease to other
- contagious (red): The resident have the disease and is contagious
- immuned (green): The resident is immumed from the disease
- dead (disappear): the resident is dead and can't effect others

There are basic statistics generated after the simulation is finished. 



Setup Instruction: (currently Mac only, will add support for Linux)
===================================================================

- Install QT http://qt-project.org/doc/qt-4.8/installation.html
- Install qwt http://qwt.sourceforge.net/qwtinstall.html .Move qwt.framework to /Library/Frameworks
- Open epidemicsimulator.pro

Some of the original documentation can be found in 
http://www.cs.umb.edu/~ngdzu/cs410/index.html


TODO:
- clean up


