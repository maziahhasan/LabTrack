from django.db import models
from django.contrib.auth.models import AbstractUser

class Building(models.Model):
    name = models.CharField(max_length=100)
    address = models.TextField()

class Room(models.Model):
    building = models.ForeignKey(Building, on_delete=models.CASCADE)
    room_number = models.CharField(max_length=10)

class Instructor(models.Model):
    name = models.CharField(max_length=100)
    email = models.EmailField()

class TA(models.Model):
    name = models.CharField(max_length=100)
    email = models.EmailField()

class Lab(models.Model):
    name = models.CharField(max_length=100)
    section = models.CharField(max_length=10)
    instructor = models.ForeignKey(Instructor, on_delete=models.CASCADE)
    tas = models.ManyToManyField(TA)
    venue = models.ForeignKey(Room, on_delete=models.CASCADE)

class Schedule(models.Model):
    lab = models.OneToOneField(Lab, on_delete=models.CASCADE)
    expected_start_time = models.TimeField()
    expected_end_time = models.TimeField()

class TimeSheet(models.Model):
    lab = models.ForeignKey(Lab, on_delete=models.CASCADE)
    actual_start_time = models.TimeField()
    actual_end_time = models.TimeField()
    date = models.DateField()

class Attendant(AbstractUser):
    building = models.OneToOneField(Building, on_delete=models.CASCADE)
