#!/bin/bash
echo 'Укажите путь до файла'
read monkey
echo 'Укажите строку для замены'
read pig
echo 'Введите новую строку'
read lama
monkey2="$monkey"".temp"
sed -e "s/$pig/$lama/gi" $monkey > $monkey2 && mv $monkey2 $monkey

date = -r <fileslog> +"%Y+%m+%t"
size
sha-sum
