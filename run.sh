#!/bin/bash

cd  ./scripts
gcc -o jarvis brain.c chat.c hola.c jarvis.c ping.c
xterm -e './jarvis' 2>/dev/null & disown
cd ..
