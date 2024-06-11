#!/bin/bash

# Verificar si GCC está instalado
if command -v gcc &> /dev/null
then
    echo "GCC ya está instalado en el sistema."
else
    # Detectar la distribución actual
    distro=$(awk -F= '$1=="ID" {print $2}' /etc/os-release)

    # Instalar GCC según la distribución
    case "$distro" in
        debian|ubuntu|parrot)
            sudo apt update
            sudo apt install -y gcc
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
gcc -o jarvis brain.c chat.c hola.c jarvis.c ping.c mkdir.c find.c
xterm -e './jarvis' 2>/dev/null & disown
cd ..
