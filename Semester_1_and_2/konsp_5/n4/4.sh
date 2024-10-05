#!/bin/bash

# Путь к именованному каналу
f_way="/home/fram/vsescri/konsp_5/n4"
# Создаем именованный канал, если он не существует
if [ ! -p "$f_way" ]; then
    mkfifo "$f_way"
fi
# Бесконечный цикл для чтения и вывода сообщений
while true; do
    if read -r line < "$f_way"; then
        # Получаем текущую дату и время
        curr=$(date "+%Y-%m-%d %H:%M:%S")
        
        # Выводим сообщение с датой
        echo "[$curr] $line"
    fi
done


