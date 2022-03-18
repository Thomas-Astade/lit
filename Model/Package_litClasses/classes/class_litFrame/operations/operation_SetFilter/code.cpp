milestoneListCtrl->SetFilter(
        plannedCheckBox->GetValue(),
        delayedCheckBox->GetValue(),
        startedCheckBox->GetValue(),
        finishedCheckBox->GetValue(),
        canceledCheckBox->GetValue(),
        ResourceFilterTextCtrl->GetValue(),
        ProjectFilterTextCtrl->GetValue());
focused = -1;
issueGantt->SetSelectedItem(focused);
nameTextCtrl->Clear();
resourceTextCtrl->Clear();
projectsTextCtrl->Clear();
descriptionTextCtrl->Clear();
issueGantt->Refresh();
issueTrend->Refresh();
