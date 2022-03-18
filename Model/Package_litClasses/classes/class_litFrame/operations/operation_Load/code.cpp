if (!dir.empty())
{
	currentFile = dir;
	wxFileName aFile(currentFile);
	wxFileConfig aConfig(wxEmptyString, wxEmptyString, aFile.GetFullPath(),
		wxEmptyString, wxCONFIG_USE_LOCAL_FILE | wxCONFIG_USE_RELATIVE_PATH);
	milestoneListCtrl->Load(aConfig);
	SetTitle(currentFile);
	isChanged = false;
    issueGantt->Refresh();
    issueTrend->Refresh();
}
