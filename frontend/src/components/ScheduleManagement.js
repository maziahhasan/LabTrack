import React, { useState, useEffect } from 'react';
import axios from 'axios';

const ScheduleManagement = () => {
    const [schedules, setSchedules] = useState([]);

    useEffect(() => {
        axios.get('/reports/schedule/')
            .then(response => setSchedules(response.data))
            .catch(error => console.error(error));
    }, []);

    return (
        <div>
            <h2>Schedule Management</h2>
            <ul>
                {schedules.map(schedule => (
                    <li key={schedule.lab}>
                        {schedule.lab} - {schedule.section} ({schedule.expected_start_time} to {schedule.expected_end_time})
                    </li>
                ))}
            </ul>
        </div>
    );
};

export default ScheduleManagement;
