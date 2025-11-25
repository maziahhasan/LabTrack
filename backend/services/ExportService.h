#pragma once
#include <QString>
#include <QTableWidget>
#include <string>

/**
 * ExportService - Handles data export operations
 * Separates export logic from UI layer following SRP and separation of concerns
 */
class ExportService {
public:
    /**
     * Export table data to CSV format (Excel-compatible)
     * @param fileName - Full path to save the CSV file
     * @param title - Report title
     * @param table - QTableWidget containing data to export
     * @param summary - Optional summary text to include at top
     * @return true if export successful, false otherwise
     */
    static bool exportToCSV(const QString& fileName, 
                           const QString& title, 
                           QTableWidget* table, 
                           const QString& summary = "");

private:
    /**
     * Escape special characters in CSV field
     * Handles commas, quotes, and newlines
     */
    static QString escapeCSVField(const QString& field);
};
