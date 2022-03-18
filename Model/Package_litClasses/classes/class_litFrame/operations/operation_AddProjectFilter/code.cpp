//~~ void AddProjectFilter(wxCommandEvent& event) [litFrame] ~~
std::set<wxString> tokens = milestoneListCtrl->GetProjectTokens();

unsigned int i = event.GetId();

for (std::set<wxString>::iterator it = tokens.begin(); it != tokens.end() && i >= ID_AddProjectFilter; it++, i--)
{
	if (i == ID_AddProjectFilter)
	{
	 	if (ProjectFilterTextCtrl->GetValue().empty())
			ProjectFilterTextCtrl->AppendText(*it);
		else
			ProjectFilterTextCtrl->AppendText(", " + *it);
        
        return;
	}
}