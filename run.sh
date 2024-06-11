#!/bin/bash

/usr/bin/gcc -o jarvis brain.c chat.c hola.c jarvis.c ping.c

/usr/bin/xterm -e './scripts/jarvis' 2>/dev/null & disown
