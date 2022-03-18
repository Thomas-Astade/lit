milestoneListCtrl->SetEnd(focused, endCalendarCtrl->GetDate());
NotifyModification();

if (endCalendarCtrl->GetDate() < startCalendarCtrl->GetDate())
{
    startCalendarCtrl->SetDate(endCalendarCtrl->GetDate());
    milestoneListCtrl->SetStart(focused, startCalendarCtrl->GetDate());
    wxMessageBox("Changed the start date, too, because otherwise it's later than the end date.");
}
issueGantt->Refresh();
issueTrend->Refresh();
