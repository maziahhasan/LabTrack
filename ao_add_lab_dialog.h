#pragma once
#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QTimeEdit>
#include <QDateEdit>
#include <QDialogButtonBox>
#include "backend/repositories/InstructorRepository.h"
#include "backend/repositories/RoomRepository.h"
#include "backend/models/Lab.h"

class AOAddLabDialog : public QDialog {
    Q_OBJECT
public:
    AOAddLabDialog(InstructorRepository &instrRepo, RoomRepository &roomRepo, QWidget *parent = nullptr);
    // Prefill using existing lab
    AOAddLabDialog(InstructorRepository &instrRepo, RoomRepository &roomRepo, const Lab &lab, QWidget *parent = nullptr);

    QString courseCode() const;
    QString section() const;
    int selectedInstructorId() const;
    int selectedRoomId() const;
    QString dayOfWeek() const;
    QTime startTime() const;
    QTime endTime() const;
    QDate semesterStart() const;
    QDate semesterEnd() const;

private:
    QLineEdit *editCourse;
    QLineEdit *editSection;
    QComboBox *comboInstructor;
    QComboBox *comboRoom;
    QComboBox *comboDay;
    QTimeEdit *timeStart;
    QTimeEdit *timeEnd;
    QDateEdit *dateSemesterStart;
    QDateEdit *dateSemesterEnd;
    QDialogButtonBox *buttons;
};
