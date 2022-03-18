//~~ void AddProject(wxCommandEvent& event) [litFrame] ~~
std::set<wxString> tokens = milestoneListCtrl->GetProjectTokens();

unsigned int i = event.GetId();

for (std::set<wxString>::iterator it = tokens.begin(); it != tokens.end() && i >= ID_AddProject; it++, i--)
{
	if (i == ID_AddProject)
	{
	 	if (projectsTextCtrl->GetValue().empty())
			projectsTextCtrl->AppendText(*it);
		else
			projectsTextCtrl->AppendText(", " + *it);
        
        return;
	}
}