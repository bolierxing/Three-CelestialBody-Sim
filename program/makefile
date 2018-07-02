objects = Vector3D.o Position.o Gravity.o Velocity.o CelestialBody.o Sim.o
target :$(objects)
	g++ -o Sim $(objects) `root-config --cflags --libs`
$(objects): %.o: %.cpp 
	g++ -std=c++11 -c  $< -o $@ `root-config --cflags --libs`
.PHONY : clean
clean :
	rm -f Sim $(objects) *.dat *.gif
