@echo off  
set /p directoryWeek="Please enter the Number of week to make project folders: "
set /p directoryProj="Please enter the project name: "
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%"
mkdir "E:\ITI ES\10. C++\CPP\NeuronetiX\Week%directoryWeek%\%directoryProj%"
echo Done
pause