#include "ao_add_lab_dialog.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QTime>
#include <QMessageBox>

AOAddLabDialog::AOAddLabDialog(InstructorRepository &instrRepo, RoomRepository &roomRepo, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Add Lab / Schedule");
    editCourse = new QLineEdit(this);
    editSection = new QLineEdit(this);

    comboInstructor = new QComboBox(this);
    auto instrs = instrRepo.getAll();
    comboInstructor->addItem("(Unassigned)", QVariant(0));
    for (const auto &ins : instrs) {
        comboInstructor->addItem(QString::fromStdString(ins.getName()), QVariant(ins.getId()));
    }

    comboRoom = new QComboBox(this);
    comboRoom->addItem("(Unassigned)", QVariant(0));
    auto rooms = roomRepo.getAll();
    for (const auto &r : rooms) {
        comboRoom->addItem(QString::fromStdString(r.getName()), QVariant(r.getId()));
    }

    comboDay = new QComboBox(this);
    comboDay->addItems({"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"});

    timeStart = new QTimeEdit(QTime(9,0), this);
    timeStart->setDisplayFormat("HH:mm");
    timeEnd = new QTimeEdit(QTime(11,0), this);
    timeEnd->setDisplayFormat("HH:mm");

    buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);

    QFormLayout *form = new QFormLayout;
    form->addRow("Course Code:", editCourse);
    form->addRow("Section:", editSection);
    form->addRow("Instructor:", comboInstructor);
    form->addRow("Room:", comboRoom);
    form->addRow("Day:", comboDay);
    form->addRow("Start Time:", timeStart);
    form->addRow("End Time:", timeEnd);

    QVBoxLayout *l = new QVBoxLayout;
    l->addLayout(form);
    l->addWidget(buttons);
    setLayout(l);

    connect(buttons, &QDialogButtonBox::accepted, this, [this]() {
        // basic validation: start < end
        if (timeStart->time() >= timeEnd->time()) {
            QMessageBox::warning(this, "Invalid Times", "Start time must be before End time.");
            return;
        }
        if (editCourse->text().trimmed().isEmpty()) {
            QMessageBox::warning(this, "Missing Course", "Please enter a course code.");
            return;
        }
        accept();
    });
    connect(buttons, &QDialogButtonBox::rejected, this, &AOAddLabDialog::reject);
}

AOAddLabDialog::AOAddLabDialog(InstructorRepository &instrRepo, RoomRepository &roomRepo, const Lab &lab, QWidget *parent)
    : AOAddLabDialog(instrRepo, roomRepo, parent)
{
    // Prefill fields from provided lab
    editCourse->setText(QString::fromStdString(lab.getCourseCode()));
    editSection->setText(QString::fromStdString(lab.getSection()));
    // select instructor if present
    int iid = lab.getInstructorId();
    for (int i = 0; i < comboInstructor->count(); ++i) {
        if (comboInstructor->itemData(i).toInt() == iid) { comboInstructor->setCurrentIndex(i); break; }
    }
    int rid = lab.getRoomId();
    for (int i = 0; i < comboRoom->count(); ++i) {
        if (comboRoom->itemData(i).toInt() == rid) { comboRoom->setCurrentIndex(i); break; }
    }
    // schedule
    ScheduleTiming s = lab.getSchedule();
    for (int i = 0; i < comboDay->count(); ++i) {
        if (comboDay->itemText(i) == QString::fromStdString(s.getDay())) { comboDay->setCurrentIndex(i); break; }
    }
    timeStart->setTime(QTime::fromString(QString::fromStdString(s.getStart()), "HH:mm"));
    timeEnd->setTime(QTime::fromString(QString::fromStdString(s.getEnd()), "HH:mm"));
}

QString AOAddLabDialog::courseCode() const { return editCourse->text().trimmed(); }
QString AOAddLabDialog::section() const { return editSection->text().trimmed(); }
int AOAddLabDialog::selectedInstructorId() const { return comboInstructor->currentData().toInt(); }
int AOAddLabDialog::selectedRoomId() const { return comboRoom->currentData().toInt(); }
QString AOAddLabDialog::dayOfWeek() const { return comboDay->currentText(); }
QTime AOAddLabDialog::startTime() const { return timeStart->time(); }
QTime AOAddLabDialog::endTime() const { return timeEnd->time(); }
