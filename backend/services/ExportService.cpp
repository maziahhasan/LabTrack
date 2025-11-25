#include "ExportService.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

bool ExportService::exportToCSV(const QString& fileName, 
                                const QString& title, 
                                QTableWidget* table, 
                                const QString& summary) {
    if (!table || fileName.isEmpty()) {
        return false;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);
    
    // Write title
    out << title << "\n";
    
    // Write optional summary
    if (!summary.isEmpty()) {
        out << summary << "\n";
    }
    out << "\n";
    
    // Write headers
    for (int col = 0; col < table->columnCount(); ++col) {
        if (col > 0) out << ",";
        QString header = table->horizontalHeaderItem(col) 
            ? table->horizontalHeaderItem(col)->text() 
            : QString("Column %1").arg(col + 1);
        out << escapeCSVField(header);
    }
    out << "\n";
    
    // Write data rows
    for (int row = 0; row < table->rowCount(); ++row) {
        for (int col = 0; col < table->columnCount(); ++col) {
            if (col > 0) out << ",";
            QString cellText = table->item(row, col) 
                ? table->item(row, col)->text() 
                : "";
            out << escapeCSVField(cellText);
        }
        out << "\n";
    }
    
    file.close();
    return true;
}

QString ExportService::escapeCSVField(const QString& field) {
    // If field contains comma, quote, or newline, wrap in quotes
    if (field.contains(',') || field.contains('"') || field.contains('\n')) {
        QString escaped = field;
        escaped.replace("\"", "\"\""); // Double any quotes
        return "\"" + escaped + "\"";
    }
    return field;
}
