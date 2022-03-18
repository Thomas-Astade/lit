if (isChanged)
{
	int answere = wxMessageDialog(this,"You made changes. Save?","Save Changes?",wxCANCEL | wxYES | wxNO | wxICON_QUESTION).ShowModal();

	wxCommandEvent anEvent;

	if (answere==wxID_YES)
		Save(anEvent);

	if (answere==wxID_CANCEL)
		return;
}

const wxString& dir = wxFileSelector("File to open","","","","*.tfo",0,this);
Load(dir);