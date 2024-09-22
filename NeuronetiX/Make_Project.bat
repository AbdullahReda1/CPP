@echo off


set /p directoryWeek="Please enter the Number of week to make project folders: "
set /p directoryProj="Please enter the project name: "

mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%\%directoryProj%"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%\%directoryProj%\build"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%\%directoryProj%\doc"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%\%directoryProj%\include"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%\%directoryProj%\src"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%\%directoryProj%\tests"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%\%directoryProj%\third-party"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%\%directoryProj%\ui"

echo Done.

REM Create an empty CMakeLists.txt file
echo > "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%\%directoryProj%\CMakeLists.txt"

REM Create an empty src/main.cpp file
echo > "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%\%directoryProj%\src\main.cpp"

REM Create an empty tests/unit_tests.cpp file
echo > "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%\%directoryProj%\tests\unit_tests.cpp"

REM Create an empty ui/main.cpp file
echo > "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%\%directoryProj%\ui\main.cpp"


pause