import React, { useState } from 'react';
import axios from 'axios';

const Reports = () => {
    const [reportType, setReportType] = useState('');
    const [reportData, setReportData] = useState([]);

    const handleGenerateReport = () => {
        const url = reportType === 'schedule' ? '/reports/schedule/' : '/reports/timesheet/';
        axios.get(url)
            .then(response => setReportData(response.data))
            .catch(error => console.error(error));
    };

    return (
        <div>
            <h2>Reports</h2>
            <select onChange={e => setReportType(e.target.value)}>
                <option value="">Select Report Type</option>
                <option value="schedule">Lab Schedule</option>
                <option value="timesheet">Time Sheet</option>
            </select>
            <button onClick={handleGenerateReport}>Generate Report</button>
            <ul>
                {reportData.map((item, index) => (
                    <li key={index}>{JSON.stringify(item)}</li>
                ))}
            </ul>
        </div>
    );
};

export default Reports;
