# TODO for AO GUI Implementation

- [x] Create ao_mainwindow.ui: Design the main window with sidebar buttons (Dashboard, Manage Labs, Manage Instructors, Manage TAs, Schedule Labs, Reports) and stacked widget pages.
- [x] Create ao_mainwindow.h: Declare AOMainWindow class with UI, repositories, and slots.
- [x] Create ao_mainwindow.cpp: Implement the class logic, signal connections, data loading, CRUD operations.
- [x] Update CMakeLists.txt: Add ao_mainwindow.cpp and ao_mainwindow.h to the build.
- [ ] Update startpage.cpp or login.cpp: Add navigation to AO window based on user role.
- [ ] Build and test the application.

# TODO for Instructor GUI Implementation

- [x] Create instructor_mainwindow.ui: Design the main window with sidebar buttons (Dashboard, My Labs, Lab Details, Timesheet, Notifications, Profile) and stacked widget pages.
- [x] Create instructor_mainwindow.h: Declare InstructorMainWindow class with UI, repositories, and slots.
- [x] Create instructor_mainwindow.cpp: Implement the class logic, signal connections, data loading, and profile updates.
- [ ] Update CMakeLists.txt: Add instructor_mainwindow.cpp and instructor_mainwindow.h to the build.
- [ ] Update startpage.cpp: Add navigation to Instructor window based on user role.
- [ ] Build and test the application.
