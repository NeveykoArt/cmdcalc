----#Configure

cmake --preset debug

cmake --preset release

----#Build

cmake --build --preset debug

cmake --build --preset release

----#PowerOn

./build/debug/bin/cmdcalc --input "-1.1 - (5 + 2 * (2 + 3)) / 10"

./build/debug/bin/Tests
