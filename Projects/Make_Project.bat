@echo off


set /p directoryProj="Please enter the project name: "

mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\%directoryProj%"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\%directoryProj%\build"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\%directoryProj%\doc"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\%directoryProj%\include"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\%directoryProj%\src"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\%directoryProj%\tests"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\%directoryProj%\third-party"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\%directoryProj%\ui"

echo Done.

REM Create an empty CMakeLists.txt file
echo > "E:\ITI ES\10. C++\CPP\NeuronetiX\%directoryProj%\CMakeLists.txt"

REM Create an empty src/main.cpp file
echo > "E:\ITI ES\10. C++\CPP\NeuronetiX\%directoryProj%\src\main.cpp"

REM Create an empty tests/unit_tests.cpp file
echo > "E:\ITI ES\10. C++\CPP\NeuronetiX\%directoryProj%\tests\unit_tests.cpp"

REM Create an empty ui/main.cpp file
echo > "E:\ITI ES\10. C++\CPP\NeuronetiX\%directoryProj%\ui\main.cpp"


pause