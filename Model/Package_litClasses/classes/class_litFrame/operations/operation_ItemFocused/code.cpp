focused = event.GetIndex();

issueGantt->SetSelectedItem(focused);
issueTrend->SetSelectedItem(focused);

nameTextCtrl->SetValue(milestoneListCtrl->GetName(focused));
resourceTextCtrl->SetValue(milestoneListCtrl->GetResource(focused));
descriptionTextCtrl->SetValue(milestoneListCtrl->GetDescription(focused));
projectsTextCtrl->SetValue(milestoneListCtrl->GetProjects(focused));
milestoneCheckBox->SetValue(milestoneListCtrl->GetIsMilestone(focused));

SetCalenderValues();
