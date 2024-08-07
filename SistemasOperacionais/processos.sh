#!/bin/bash
# Função para capturar a interrupção (Ctrl+C) e finalizar o script
trap 'echo "Processo terminado."; exit 0' SIGINT
# Inicializando o contador
contador=0
# Loop infinito para contar e interagir
while true; do
    # Incrementa o contador
    contador=$((contador + 1))

    # Mostra o contador e aguarda a entrada do usuário
    echo "Contador: $contador. Pressione Enter para continuar, ou Ctrl+C para parar."

    # Aguarda entrada do usuário
    read -r # O '-r' impede que o Bash interprete caracteres de escape
    # Limpa a tela para melhor visibilidade
    clear
done