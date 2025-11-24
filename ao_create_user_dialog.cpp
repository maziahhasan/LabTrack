#include "ao_create_user_dialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QMessageBox>

AOCreateUserDialog::AOCreateUserDialog(AuthService *auth, InstructorRepository *irepo, TARepository *trepo, HODRepository *hrepo, QWidget *parent)
    : QDialog(parent), authService(auth), instrRepo(irepo), taRepo(trepo), hodRepo(hrepo)
{
    setWindowTitle("Create User (AO)");
    auto *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("Username:"));
    editUsername = new QLineEdit(this); layout->addWidget(editUsername);

    layout->addWidget(new QLabel("Password:"));
    editPassword = new QLineEdit(this); editPassword->setEchoMode(QLineEdit::Password); layout->addWidget(editPassword);

    layout->addWidget(new QLabel("Full Name:"));
    editFullName = new QLineEdit(this); layout->addWidget(editFullName);

    layout->addWidget(new QLabel("Email:"));
    editEmail = new QLineEdit(this); layout->addWidget(editEmail);

    layout->addWidget(new QLabel("Role:"));
    comboRole = new QComboBox(this);
    comboRole->addItem("TA");
    comboRole->addItem("Instructor");
    comboRole->addItem("HOD");
    comboRole->addItem("AcademicOfficer");
    layout->addWidget(comboRole);

    auto *h = new QHBoxLayout();
    btnOk = new QPushButton("Create", this);
    btnCancel = new QPushButton("Cancel", this);
    h->addWidget(btnOk); h->addWidget(btnCancel);
    layout->addLayout(h);

    connect(btnOk, &QPushButton::clicked, this, &AOCreateUserDialog::onOk);
    connect(btnCancel, &QPushButton::clicked, this, &AOCreateUserDialog::reject);
}

void AOCreateUserDialog::onOk() {
    QString username = editUsername->text();
    QString password = editPassword->text();
    QString fullname = editFullName->text();
    QString email = editEmail->text();
    QString role = comboRole->currentText();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Create User", "Username and password are required.");
        return;
    }

    // create account as AO
    bool ok = authService->registerUser(username.toStdString(), password.toStdString(), role.toStdString(), "AcademicOfficer");
    if (!ok) {
        QMessageBox::critical(this, "Create User", "Failed to create user (exists or no privileges).");
        return;
    }

    // update created domain record with full info
    if (role == "Instructor" && instrRepo) {
        auto v = instrRepo->load();
        for (auto &ins : v) {
            if (ins.getName() == username.toStdString()) {
                ins.setName(fullname.isEmpty() ? username.toStdString() : fullname.toStdString());
                if (!email.isEmpty()) ins.setEmail(email.toStdString());
                instrRepo->update(ins);
                break;
            }
        }
    } else if (role == "TA" && taRepo) {
        auto v = taRepo->load();
        for (auto &t : v) {
            if (t.getName() == username.toStdString()) {
                TA updated(t.getId(), fullname.isEmpty() ? username.toStdString() : fullname.toStdString());
                taRepo->update(updated);
                break;
            }
        }
    } else if (role == "HOD" && hodRepo) {
        auto v = hodRepo->load();
        for (auto &h : v) {
            if (h.getName() == username.toStdString()) {
                HOD updated(h.getId(), fullname.isEmpty() ? username.toStdString() : fullname.toStdString(), "");
                for (auto &hh : v) if (hh.getId() == h.getId()) hh = updated;
                hodRepo->save(v);
                break;
            }
        }
    }

    QMessageBox::information(this, "Create User", "User created successfully.");
    accept();
}
