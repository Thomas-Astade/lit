if (isChanged)
{
	int answer = wxMessageDialog(this,"You made changes. Save?","Save Changes?",wxCANCEL | wxYES | wxNO | wxICON_QUESTION).ShowModal();

	wxCommandEvent anEvent;

	if (answer == wxID_YES)
		Save(anEvent);

	if (answer == wxID_CANCEL)
		return;
}

isChanged = false;
currentFile.clear();
SetTitle(currentFile);

milestoneListCtrl->New();

issueGantt->Refresh();
issueTrend->Refresh();
