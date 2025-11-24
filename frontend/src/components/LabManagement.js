import React, { useState, useEffect } from 'react';
import axios from 'axios';

const LabManagement = () => {
    const [labs, setLabs] = useState([]);
    const [newLab, setNewLab] = useState({ name: '', section: '', instructor: '', venue: '' });

    useEffect(() => {
        axios.get('/labs/')
            .then(response => setLabs(response.data))
            .catch(error => console.error(error));
    }, []);

    const handleAddLab = () => {
        axios.post('/labs/', newLab)
            .then(response => setLabs([...labs, response.data]))
            .catch(error => console.error(error));
    };

    return (
        <div>
            <h2>Lab Management</h2>
            <ul>
                {labs.map(lab => (
                    <li key={lab.id}>{lab.name} - {lab.section}</li>
                ))}
            </ul>
            <div>
                <input
                    type="text"
                    placeholder="Lab Name"
                    value={newLab.name}
                    onChange={e => setNewLab({ ...newLab, name: e.target.value })}
                />
                <input
                    type="text"
                    placeholder="Section"
                    value={newLab.section}
                    onChange={e => setNewLab({ ...newLab, section: e.target.value })}
                />
                <button onClick={handleAddLab}>Add Lab</button>
            </div>
        </div>
    );
};

export default LabManagement;
