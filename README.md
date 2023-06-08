----#Конфигурация

cmake --preset debug

cmake --preset release

----#Сборка

cmake --build --preset debug

cmake --build --preset release

----#Запуск

./build/debug/bin/cmdcalc --input "-1.1 - (5 + 2 * (2 + 3)) / 10"

./build/debug/bin/Tests
