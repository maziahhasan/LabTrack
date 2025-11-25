# LabTrack - University Lab Management System

A comprehensive C++ Qt-based desktop application for managing university laboratory sessions, schedules, and personnel.

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [System Architecture](#system-architecture)
- [User Roles](#user-roles)
- [Core Functionality](#core-functionality)
- [Technical Stack](#technical-stack)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage Guide](#usage-guide)
- [Data Models](#data-models)
- [Security](#security)
- [Building from Source](#building-from-source)

---

## 🎯 Overview

LabTrack is a complete lab management solution designed for universities to efficiently manage laboratory sessions, personnel, and resources. The system implements the following requirements:

### **System Requirements Implemented:**

**1. Lab Information Management**
- Stores comprehensive lab data including sections, timings, instructors, and TAs
- Venue management (rooms and buildings)
- Support for multiple TAs per lab section
- Single instructor assignment per lab

**2. Two-Type Timing System**
- **Schedule Timing (Expected)**: Populated by Academic Officer
  - Day of week, start/end times
  - Semester date ranges
- **Actual Timing (Timesheet)**: Filled by Building Attendant
  - Actual start/end times recorded
  - Leave tracking capability

**3. Personnel Management**
- Academic Officer: Populates basic data and schedules
- Building Attendant: One per building, fills timesheets for their building only
- Instructors: View labs and request makeup sessions
- HOD: Generate comprehensive reports

**4. Reporting System (HOD)**
- Complete lab schedule for entire week
- Filled timesheet for all labs in a given week
- Individual lab time sheet for semester with:
  - Total contact hours calculation
  - Leave tracking (explicit and implicit)
  - Makeup session integration

**5. Makeup Lab Workflow**
- Instructors request makeup labs via Academic Office
- Attendants enter actual times in timesheet
- Reports automatically update with makeup sessions
- Updated contact hours and leave calculations

---

## ✨ Features

### Role-Based Access Control
- **Academic Officer (AO)**: System administration and lab scheduling
- **Head of Department (HOD)**: Report generation and oversight
- **Instructor**: Lab viewing and makeup request submission
- **Building Attendant**: Timesheet entry for assigned building
- **Teaching Assistant (TA)**: Lab information access

### Core Capabilities
✅ **Lab Management**
- Create/edit/delete lab sections
- Assign instructors and multiple TAs
- Define room and building venues
- Set weekly schedule with semester dates
- Semester-wide scheduling with clash detection

✅ **Time Tracking**
- Schedule timings (expected start/end)
- Actual timings (timesheet entry by attendants)
- Leave tracking (marked as 00:00-00:00)
- Duration calculations

✅ **Makeup Lab Workflow**
- Instructors request makeup sessions
- Specify date, time, and room
- AO approves/rejects with clash detection
- Automatic scheduling upon approval

✅ **Comprehensive Reporting**
- Weekly lab schedules (calendar-based)
- Weekly timesheets for all labs
- Individual lab history with totals
- Contact hours, leaves, and makeup sessions
- Makeup request tracking
- **Excel-compatible CSV export**

✅ **Clash Detection**
- Room availability validation
- Instructor availability checking
- Prevents double-booking across all scheduling operations

---

## 🏗️ System Architecture

### Layered Architecture (following SDA principles)

```
┌─────────────────────────────────────┐
│         Presentation Layer          │
│   (Qt Widgets - UI Classes)         │
│   - Login, Role-specific windows    │
└────────────┬────────────────────────┘
             │
┌────────────▼────────────────────────┐
│         Service Layer               │
│   (Business Logic)                  │
│   - AuthService                     │
│   - ReportService                   │
│   - MakeupService                   │
│   - LabService                      │
│   - ExportService                   │
└────────────┬────────────────────────┘
             │
┌────────────▼────────────────────────┐
│       Repository Layer              │
│   (Data Access)                     │
│   - LabRepository                   │
│   - UserRepository                  │
│   - InstructorRepository            │
│   - RoomRepository, etc.            │
└────────────┬────────────────────────┘
             │
┌────────────▼────────────────────────┐
│         Data Layer                  │
│   (Binary Files)                    │
│   - labs.bin, users.txt, etc.       │
└─────────────────────────────────────┘
```

### Design Patterns Used
- **Repository Pattern**: Centralized data access
- **Service Layer Pattern**: Business logic separation
- **Factory Pattern**: User creation based on roles
- **Observer Pattern**: Qt signals/slots for UI updates
- **RAII Pattern**: Smart pointers for memory management

---

## 👥 User Roles

### 1. Academic Officer (AO)
**Primary Administrator** - Populates basic data and manages system

**Capabilities:**
- Create/manage user accounts (Instructors, TAs, HODs, Attendants)
- Schedule labs for entire semester
- Assign instructors and TAs to labs
- Define room and building allocations
- **Review and approve/reject makeup requests**
- Assign building attendants

**Dashboard:**
- Total labs count
- Total instructors
- Total TAs

---

### 2. Head of Department (HOD)
**Reporting Authority** - Generates all management reports

**Required Reports (As Per Specification):**

#### Report 1: Complete Lab Schedule for Entire Week
- Calendar-based week selection
- Shows all labs scheduled for Monday-Sunday
- Displays: Date, Day, Lab Name, Instructor, Room, Time, Duration
- Export to CSV

#### Report 2: Filled Timesheet for All Labs in Given Week
- Calendar-based week selection
- Shows actual conducted sessions for selected week
- Displays: Date, Lab, Instructor, Start Time, End Time, Duration
- Includes leaves (0 duration entries)
- Export to CSV

#### Report 3: Lab Time Sheet for Semester (Individual Lab)
- Select specific lab from dropdown
- View all sessions across entire semester
- **Calculates and displays:**
  - **Total Contact Hours**: Sum of all actual session durations
  - **Total Leaves**: Explicit (0-hour entries) + Implicit (expected - recorded)
  - **Makeup Sessions**: Sessions not on scheduled day
- Export to CSV with summary totals

#### Report 4: Makeup Requests Tracking
- View all makeup requests system-wide
- Status filtering (Pending/Approved/Rejected)
- Export to CSV

---

### 3. Instructor
**Lab Conductor** - Requests makeup labs when needed

**Capabilities:**
- View assigned labs with schedules
- **Request makeup lab through Academic Office**
- View request status
- See room assignments

**Makeup Request Workflow:**
1. Select lab requiring makeup
2. Specify date, time, and room
3. Provide reason
4. Submit to Academic Office
5. AO reviews and approves/rejects
6. If approved, **attendant enters actual times in timesheet**
7. **Reports automatically include makeup with updated hours and leaves**

---

### 4. Building Attendant
**Timesheet Manager** - Fills actual timings for their building

**Capabilities:**
- **Fill timesheets for labs in assigned building only**
- Enter actual start and end times
- Mark leaves (00:00-00:00)
- View submitted timesheets

**Security Enforcement:**
- Can only access labs in their assigned building
- Each building has separate attendant

**Leave Entry:**
- Set both start and end to 00:00
- System recognizes as leave (0 hours)

---

### 5. Teaching Assistant (TA)
**Lab Support** - Basic access to lab information

**Capabilities:**
- View assigned labs
- Check schedules

---

## 🔧 Core Functionality

### Schedule vs. Actual Timing (Two-Type System)

#### Schedule Timing (Expected)
**Populated by:** Academic Officer during lab creation

**Data Fields:**
- Day of Week (Monday, Tuesday, etc.)
- Start Time (e.g., 09:00)
- End Time (e.g., 11:00)
- Semester Start Date (e.g., 2024-09-01)
- Semester End Date (e.g., 2024-12-15)

**Semester-Wide Scheduling:**
When AO creates a lab, the system:
1. Calculates all weeks between semester dates
2. Generates expected sessions for specified day
3. Enables clash detection for all future sessions

#### Actual Timing (Timesheet)
**Filled by:** Building Attendant after lab completion

**Data Fields:**
- Date (specific session date)
- Actual Start Time
- Actual End Time
- Duration (auto-calculated)
- Notes

**Leave Marking:**
- Start: 00:00, End: 00:00
- Duration: 0.0 hours
- Counted as explicit leave

---

### Makeup Lab Complete Workflow

```
Step 1: Instructor Requests
┌────────────────────────┐
│ Instructor submits     │
│ makeup request via     │
│ Academic Office        │
└───────────┬────────────┘
            │
            ▼
Step 2: Academic Office Reviews
┌────────────────────────┐
│ AO sees request in     │
│ Makeup Requests page   │
│                        │
│ Can Accept or Reject   │
└───────────┬────────────┘
            │
     ┌──────┴───────┐
     ▼              ▼
┌─────────┐    ┌─────────┐
│ Accept  │    │ Reject  │
└────┬────┘    └────┬────┘
     │              │
     ▼              ▼
Step 3a:        Step 3b:
Clash Detection  Status: Rejected
- Room check
- Instructor check
     │
     ▼ (No clash)
┌────────────────────────┐
│ Create ActualTiming    │
│ Status: Approved       │
└───────────┬────────────┘
            │
            ▼
Step 4: Attendant Records (Already Done)
┌────────────────────────┐
│ ActualTiming exists    │
│ Attendant can view in  │
│ timesheet if needed    │
└───────────┬────────────┘
            │
            ▼
Step 5: Reports Update
┌────────────────────────┐
│ HOD generates reports: │
│ - Weekly timesheet     │
│   shows makeup         │
│ - Lab history shows:   │
│   * Updated contact hrs│
│   * Makeup count       │
│   * Updated leaves     │
└────────────────────────┘
```

**Key Implementation Detail:**
When AO accepts makeup request, system immediately creates ActualTiming record. Attendant doesn't need to fill it separately - it's already in the timesheet for that week.

---

### Report Calculations (As Per Requirements)

#### Contact Hours Calculation
```cpp
Total Contact Hours = Sum of all ActualTiming.duration
                      where duration > 0 
                      for specific lab across semester
```

#### Leave Calculation
```cpp
Explicit Leaves = Count of ActualTiming records
                  where duration == 0.0
                  
Expected Sessions = 15 (or calculated from semester dates)

Recorded Sessions = Count of ActualTiming records
                    where duration > 0

Implicit Leaves = Expected - Recorded - Explicit

Total Leaves = Explicit Leaves + Implicit Leaves
```

#### Makeup Session Identification
```cpp
Makeup Sessions = Count of ActualTiming records
                  where day(date) != scheduledDayOfWeek
                  
// Example: Lab scheduled for Monday
// Session on Wednesday = Makeup
```

---

## 💻 Technical Stack

### Frontend
- **Qt 6.10.0** - GUI framework
- **Qt Widgets** - UI components
- **Qt Designer** - UI design (.ui files)

### Backend
- **C++17** - Core language
- **STL** - Standard library (vector, optional, unique_ptr)
- **Custom Binary Serialization** - Data persistence

### Build System
- **CMake 3.16+** - Build configuration
- **MinGW-w64 13.1.0** - GCC compiler for Windows

---

## 📁 Project Structure

```
labtrack/
├── backend/
│   ├── models/              # Data entities
│   │   ├── Lab.h           # Lab with schedule & TAs
│   │   ├── ScheduleTiming.h # Expected schedule
│   │   ├── ActualTiming.h  # Actual timesheet
│   │   ├── MakeupRequest.h # Makeup requests
│   │   └── User.h, Instructor.h, TA.h, etc.
│   │
│   ├── repositories/        # Data access
│   │   ├── LabRepository.h/cpp
│   │   ├── ActualTimingRepository.h/cpp
│   │   └── Other entity repos...
│   │
│   └── services/           # Business logic
│       ├── AuthService.h/cpp
│       ├── ReportService.h/cpp
│       ├── MakeupService.h/cpp
│       └── ExportService.h/cpp
│
├── UI windows/             # Role-specific interfaces
│   ├── ao_mainwindow.ui/h/cpp
│   ├── hod_mainwindow.ui/h/cpp
│   ├── instructor_mainwindow.ui/h/cpp
│   └── attendant_mainwindow.ui/h/cpp
│
└── Data files/             # Binary persistence
    ├── labs.bin
    ├── actual_timings.bin
    ├── makeup_requests.bin
    └── users.txt
```

---

## 📊 Data Models

### Lab
```cpp
int id;
string courseCode;           // "CS101"
string section;              // "A"
int roomId;
int buildingId;
int instructorId;           // Single instructor
ScheduleTiming schedule;    // Expected timing
vector<int> taIds;         // Multiple TAs supported
```

### ScheduleTiming (Expected)
```cpp
string dayOfWeek;          // "Monday", "Wednesday"
string start;              // "09:00"
string end;                // "11:00"
string semesterStart;      // "2024-09-01"
string semesterEnd;        // "2024-12-15"
```

### ActualTiming (Timesheet)
```cpp
int labId;
int taId;                  // Who filled (attendant)
string date;               // "2024-11-20"
string startTime;          // "09:05"
string endTime;            // "11:00"
double duration;           // 1.92 hours (0 for leave)
string notes;
```

### MakeupRequest
```cpp
int id;
int labId;
int instructorId;
int roomId;
string date;
string time;               // "14:00-16:00"
string reason;
string status;             // Pending/Approved/Rejected
```

---

## 🚀 Installation

### Prerequisites
- Windows 10/11
- Qt 6.10.0
- MinGW-w64 13.1.0
- CMake 3.16+

### Build Steps

```bash
# Clone
git clone https://github.com/maziahhasan/LabTrack.git
cd LabTrack

# Configure
cmake -B build-mingw2 -G "MinGW Makefiles"

# Build
cmake --build build-mingw2

# Run
cd build-mingw2
./labtrack.exe
```

### First-Time Setup

1. **Create Admin Account**
   - Username: `admin`
   - Password: `adminpass`
   - Role: AcademicOfficer

2. **Setup Data (as AO)**
   - Create buildings
   - Add rooms to buildings
   - Assign building attendants
   - Create instructors and TAs
   - Create lab sections with schedules

---

## 📖 Usage Guide

### Academic Officer: Creating a Lab

1. Navigate to "Manage Labs"
2. Click "Add Lab"
3. Enter details:
   - Course Code (e.g., CS101)
   - Section (e.g., A)
   - Instructor (dropdown)
   - Room (dropdown - shows building)
   - Day of Week
   - Start/End Time
   - **Semester Start/End Dates**
4. Save

System automatically:
- Generates sessions for entire semester
- Enables clash detection
- Makes lab available for timesheet filling

### Building Attendant: Filling Timesheet

1. Go to "Fill Timesheet"
2. Select Lab (only shows labs in your building)
3. Choose Date
4. Enter Actual Start Time
5. Enter Actual End Time
6. Click Submit

**To mark leave:**
- Start: 00:00
- End: 00:00

### Instructor: Requesting Makeup

1. Navigate to "Request Makeup"
2. Select Lab (from your assigned labs)
3. Choose Date and Time
4. Select Room
5. Enter Reason
6. Submit

Wait for AO approval - check status in "My Requests"

### HOD: Generating Reports

#### Weekly Schedule
1. Click "Weekly Schedule" tab
2. Use calendar to select any date in desired week
3. View complete schedule for that week
4. Click "Export" for CSV

#### Lab History (Semester Report)
1. Click "Lab History" tab
2. Select lab from dropdown
3. View all sessions with summary:
   - Total Contact Hours
   - Total Leaves
   - Makeup Sessions
4. Click "Export" for CSV with summary

---

## 🔐 Security

### Password Hashing
```cpp
// All passwords hashed with salt
std::hash<std::string> hasher;
size_t hash = hasher(password + "labtrack_salt_2025");
```

### Access Control
- Building attendants restricted to their building
- Instructors see only assigned labs
- Role-based service layer enforcement

---

## 🧪 Testing

### Test Scenario: Complete Makeup Workflow

1. **Login as Instructor**
   - Request makeup for CS101-A on 2024-11-20 14:00-16:00

2. **Login as AO**
   - View request in Makeup Requests
   - Click Accept
   - System checks clashes
   - Creates ActualTiming

3. **Login as HOD**
   - Generate weekly timesheet for week of 2024-11-20
   - Verify makeup session appears
   - Generate lab history for CS101-A
   - Verify makeup counted, contact hours updated

---

## 🐛 Troubleshooting

**Build Error - Qt6 not found:**
```bash
set Qt6_DIR=C:/Qt/6.10.0/mingw_64/lib/cmake/Qt6
```

**Attendant can't see labs:**
- Ensure attendant assigned to building (in AO panel)

**Reports empty:**
- Check date ranges
- Ensure timesheets filled by attendant

---

## 📈 Future Enhancements

- Email notifications for approvals
- Student attendance tracking
- Equipment management
- Database backend (PostgreSQL)
- Web interface
- Automated backups

---

## 👨‍💻 Authors

**Mazia Hasan**  
GitHub: [@maziahhasan](https://github.com/maziahhasan)

---

**Last Updated:** November 25, 2025  
**Version:** 1.0.0  
**Status:** Production Ready ✅
