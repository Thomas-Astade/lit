if (focused < 0)
    return;
milestoneListCtrl->SetDependency(focused, event.GetId()-ID_Depend, event.IsChecked());
issueGantt->Refresh();