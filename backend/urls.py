from django.urls import path
from . import views

urlpatterns = [
    path('labs/', views.LabListCreateView.as_view(), name='lab-list-create'),
    path('labs/<int:pk>/', views.LabDetailView.as_view(), name='lab-detail'),
    path('timesheets/', views.TimeSheetListCreateView.as_view(), name='timesheet-list-create'),
    path('reports/schedule/', views.LabScheduleReportView.as_view(), name='lab-schedule-report'),
    path('reports/timesheet/', views.TimeSheetReportView.as_view(), name='timesheet-report'),
    path('attendants/', views.AttendantListCreateView.as_view(), name='attendant-list-create'),
    path('auth/login/', views.LoginView.as_view(), name='login'),
]
