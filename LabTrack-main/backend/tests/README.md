# Backend Tests

This contains a small, standalone C++ test program to verify `LabRepository` binary persistence and CRUD operations.

Compile and run (on Windows with g++/MinGW or MSVC):

PowerShell (MinGW/g++):

```powershell
# From repository root
g++ -std=c++17 -I. -Ibackend -Ibackend/models -Ibackend/repositories -o backend/tests/test_lab_repository.exe backend/tests/test_lab_repository.cpp
./backend/tests/test_lab_repository.exe
```

PowerShell (MSVC):

```powershell
cl /EHsc /I. /Ibackend /Ibackend/models /Ibackend/repositories backend/tests/test_lab_repository.cpp
.
```

This will write `test_labs.bin` into the repository root. Re-run the test to ensure that loading and adding labs persist data across runs.
