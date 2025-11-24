import React, { useState, useEffect } from 'react';
import axios from 'axios';

const TimeSheetManagement = () => {
    const [timeSheets, setTimeSheets] = useState([]);

    useEffect(() => {
        axios.get('/timesheets/')
            .then(response => setTimeSheets(response.data))
            .catch(error => console.error(error));
    }, []);

    return (
        <div>
            <h2>Time Sheet Management</h2>
            <ul>
                {timeSheets.map(sheet => (
                    <li key={sheet.id}>
                        {sheet.lab} - {sheet.date} ({sheet.actual_start_time} to {sheet.actual_end_time})
                    </li>
                ))}
            </ul>
        </div>
    );
};

export default TimeSheetManagement;
