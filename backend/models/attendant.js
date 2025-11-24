const mongoose = require('mongoose');
const bcrypt = require('bcrypt');

const attendantSchema = new mongoose.Schema({
    username: { type: String, required: true, unique: true },
    password: { type: String, required: true },
    building: { type: mongoose.Schema.Types.ObjectId, ref: 'Building', required: true },
});

// Hash password before saving
attendantSchema.pre('save', async function (next) {
    if (!this.isModified('password')) return next();
    this.password = await bcrypt.hash(this.password, 10);
    next();
});

module.exports = mongoose.model('Attendant', attendantSchema);
