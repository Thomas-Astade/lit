//~~ void AddResource(wxCommandEvent& event) [litFrame] ~~
std::set<wxString> tokens = milestoneListCtrl->GetResourceTokens();

unsigned int i = event.GetId();

for (std::set<wxString>::iterator it = tokens.begin(); it != tokens.end() && i >= ID_AddResource; it++, i--)
{
	if (i == ID_AddResource)
	{
	 	if (resourceTextCtrl->GetValue().empty())
			resourceTextCtrl->AppendText(*it);
		else
			resourceTextCtrl->AppendText(", " + *it);
        
        return;
	}
}