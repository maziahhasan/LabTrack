from rest_framework import serializers
from .models import Lab, TimeSheet
from django.contrib.auth.hashers import make_password
from .models import Attendant

class LabSerializer(serializers.ModelSerializer):
    class Meta:
        model = Lab
        fields = '__all__'

class TimeSheetSerializer(serializers.ModelSerializer):
    class Meta:
        model = TimeSheet
        fields = '__all__'

class AttendantSerializer(serializers.ModelSerializer):
    class Meta:
        model = Attendant
        fields = ['id', 'username', 'password', 'building']
        extra_kwargs = {'password': {'write_only': True}}

    def create(self, validated_data):
        validated_data['password'] = make_password(validated_data['password'])
        return super().create(validated_data)
