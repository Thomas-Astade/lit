//~~ void AddResourceFilter(wxCommandEvent& event) [litFrame] ~~
std::set<wxString> tokens = milestoneListCtrl->GetResourceTokens();

unsigned int i = event.GetId();

for (std::set<wxString>::iterator it = tokens.begin(); it != tokens.end() && i >= ID_AddResourceFilter; it++, i--)
{
	if (i == ID_AddResourceFilter)
	{
	 	if (ResourceFilterTextCtrl->GetValue().empty())
			ResourceFilterTextCtrl->AppendText(*it);
		else
			ResourceFilterTextCtrl->AppendText(", " + *it);
            
        return;
	}
}