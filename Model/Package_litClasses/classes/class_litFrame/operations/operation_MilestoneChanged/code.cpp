milestoneListCtrl->SetIsMilestone(focused, milestoneCheckBox->GetValue());
NotifyModification();

issueGantt->Refresh();
issueTrend->Refresh();
