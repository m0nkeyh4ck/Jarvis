#!/bin/bash

# Verificar si GCC está instalado
if command -v wmctrl &> /dev/null
then
    echo "ejecution exitosa"
else
    # Detectar la distribución actual
    distro=$(awk -F= '$1=="ID" {print $2}' /etc/os-release)

    # Instalar GCC según la distribución
    case "$distro" in
        debian|ubuntu|parrot)
            sudo apt update
            sudo apt install -y gcc wmctrl xterm rlwrap inotify-tools &> /dev/null
            ;;
        arch)
            sudo pacman -Syu --noconfirm gcc
            ;;
        *)
            echo "Distribución no compatible: $distro"
            ;;
    esac
fi

# Compilar y ejecutar el programa
cd  ./scripts
gcc -o jarvis $(find . -name '*.c')
xterm -geometry 114x12+1230+0 -e 'rlwrap ./jarvis' 2>/dev/null & disown
cd ..
