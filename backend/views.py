from rest_framework import generics
from rest_framework.response import Response
from rest_framework.views import APIView
from rest_framework.authtoken.models import Token
from django.contrib.auth import authenticate
from rest_framework import status
from .models import Lab, TimeSheet, Schedule, Attendant
from .serializers import LabSerializer, TimeSheetSerializer, AttendantSerializer

class LabListCreateView(generics.ListCreateAPIView):
    queryset = Lab.objects.all()
    serializer_class = LabSerializer

class LabDetailView(generics.RetrieveUpdateDestroyAPIView):
    queryset = Lab.objects.all()
    serializer_class = LabSerializer

class TimeSheetListCreateView(generics.ListCreateAPIView):
    queryset = TimeSheet.objects.all()
    serializer_class = TimeSheetSerializer

class LabScheduleReportView(generics.ListAPIView):
    def get_queryset(self):
        # Generate the complete lab schedule for the entire week
        return Schedule.objects.all()

    def list(self, request, *args, **kwargs):
        queryset = self.get_queryset()
        data = [
            {
                "lab": schedule.lab.name,
                "section": schedule.lab.section,
                "instructor": schedule.lab.instructor.name,
                "expected_start_time": schedule.expected_start_time,
                "expected_end_time": schedule.expected_end_time,
            }
            for schedule in queryset
        ]
        return Response(data)

class TimeSheetReportView(generics.ListAPIView):
    def get_queryset(self):
        # Filter timesheets based on query parameters
        lab_id = self.request.query_params.get('lab_id')
        if lab_id:
            return TimeSheet.objects.filter(lab_id=lab_id)
        return TimeSheet.objects.all()

    def list(self, request, *args, **kwargs):
        queryset = self.get_queryset()
        data = [
            {
                "lab": timesheet.lab.name,
                "section": timesheet.lab.section,
                "date": timesheet.date,
                "actual_start_time": timesheet.actual_start_time,
                "actual_end_time": timesheet.actual_end_time,
            }
            for timesheet in queryset
        ]
        return Response(data)

class AttendantListCreateView(generics.ListCreateAPIView):
    queryset = Attendant.objects.all()
    serializer_class = AttendantSerializer

class LoginView(APIView):
    def post(self, request, *args, **kwargs):
        username = request.data.get('username')
        password = request.data.get('password')
        print(f"Username: {username}, Password: {password}")  # Debugging

        user = authenticate(username=username, password=password)
        if user:
            token, _ = Token.objects.get_or_create(user=user)
            return Response({'token': token.key})
        return Response({'error': 'Invalid credentials'}, status=status.HTTP_401_UNAUTHORIZED)
