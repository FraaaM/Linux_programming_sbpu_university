#!/bin/bash

# Получение списка файлов в текущей директории и их переименование с изменением регистра
for file in *
do
    new_name=$(echo "$file" | tr '[:lower:]' '[:upper:]')  # Изменение регистра на прописные буквы
    mv "$file" "$new_name"  # Переименование файла
done

