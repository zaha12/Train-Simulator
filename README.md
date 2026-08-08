# Train Simulator

# Overview: 
This program simulates a train of cars traveling through 20 stops, built on top of a custom doubly-linked list.
Cars are one of four types (Passenger, Social, Cargo, Miscellaneous), each with a random number of remaining stops (1-5).
Cars are always kept in sorted order by type, with newer cars placed after older ones of the same type.
At each stop, every car's remaining stop count is decremented, cars that hit 0 are removed, a random number of new cars (1-5) are added,
and a Social car is added automatically if there's a Passenger car but no Social car. The simulation ends after 20 stops or when the train is empty. 
The linked list itself (LinkedList.hpp) is a general-purpose, templated doubly linked list, independent of anything train related.

# Files: 
main.cpp: runs the simulation loop, generates and inserts cars, and prints output at each stop.

car.hpp: Car struct and helpers for converting car type numbers into names/letters.

LinkedList.hpp: templated doubly linked list (LinkedList<T> / Node<T>), with head/tail/index insert, retrieve, remove, and search.

Makefile: Builds the exe executable, with warning flags and sanitizers enabled.

# Building 
make: Compiles the source into an executable named exe.

make clean: Removes object files and the executable.

# Running 
./exe

The train starts with 10 randomly generated cars, then runs through 20 stops.
Output is printed to standard output as cars are added/removed and as the train arrives at/departs from each stop, in [ID:TYPE:STOPS] format,
e.g.: Arrived at stop 1 [3:P:1]->[7:S:2]->[8:S:5]->[10:S:5]->[5:C:2]->[6:C:4]->[1:M:4]->[2:M:1]->[4:M:5]->[9:M:5]

To reproduce the same run across executions, set the SEED environment variable: SEED=7 ./exe
