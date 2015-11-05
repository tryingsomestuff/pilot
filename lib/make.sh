#!/bin/bash
g++ -Iheader -c src/*.cpp
ar rvs libPilot.a src/*.o
./clean.sh
