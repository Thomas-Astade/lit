milestoneListCtrl->SetStart(focused, startCalendarCtrl->GetDate());
NotifyModification();

if (endCalendarCtrl->GetDate() < startCalendarCtrl->GetDate())
{
    endCalendarCtrl->SetDate(startCalendarCtrl->GetDate());
    milestoneListCtrl->SetEnd(focused, endCalendarCtrl->GetDate());
    wxMessageBox("Changed the end date, too, because otherwize it's earlier than the start date.");
}
issueGantt->Refresh();