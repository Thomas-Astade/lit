wxFileName aFile(currentFile);

if (aFile.GetExt() != "tfo")
{
	SaveAs(event);
	return;
}

wxFileConfig aConfig(wxEmptyString, wxEmptyString, aFile.GetFullPath(),
	wxEmptyString, wxCONFIG_USE_LOCAL_FILE | wxCONFIG_USE_RELATIVE_PATH);

wxString key;
long index;

while (aConfig.GetFirstGroup(key,index))
    aConfig.DeleteGroup(key);

milestoneListCtrl->Save(aConfig);

isChanged = false;
SetTitle(currentFile);