#!/bin/bash
g++ -Iheader -c src/*.cpp
ar rvs libPilot.a *.o
./clean.sh
