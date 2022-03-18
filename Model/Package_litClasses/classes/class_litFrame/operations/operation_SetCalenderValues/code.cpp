if (focused > 0)
{
    startCalendarCtrl->SetDate(milestoneListCtrl->GetStart(focused));
    endCalendarCtrl->SetDate(milestoneListCtrl->GetEnd(focused));
    statusBox->SetSelection(milestoneListCtrl->GetState(focused));
}